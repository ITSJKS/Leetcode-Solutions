class Solution {
public:
    bool isOver(vector<string>& board, char ch) {
        for(int i = 0; i < 3; i++)
            if(board[i][0] == ch && board[i][1] == ch && board[i][2] == ch)
                return true;
        
        for(int j = 0; j < 3; j++)
            if(board[0][j] == ch && board[1][j] == ch && board[2][j] == ch)
                return true;
        
        if(board[0][0] == ch && board[1][1] == ch && board[2][2] == ch)
            return true;
        if(board[2][0] == ch && board[1][1] == ch && board[0][2] == ch)
            return true;
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int count_x = 0;
        int count_O = 0;
        for(auto x:board){
            for(auto y:x){
                if(y == 'X') count_x++;
                else if(y == 'O') count_O++;
            }
        }
        int diff = count_x - count_O;
         return ((diff == 1) &&  
            ((isOver(board, 'X') && !isOver(board, 'O')) ||
             (!isOver(board, 'X') && !isOver(board, 'O')))) ||
            ((diff == 0) && 
             ((!isOver(board, 'X') && isOver(board, 'O')) ||
             (!isOver(board, 'X') && !isOver(board, 'O'))));
    }
};