class Solution {
public:
    int totalNQueens(int n) {
         int ans = 0;
        vector <string> board(n,string(n,'.'));
        backtrack(ans,board,0,n);
        return ans;
    }
    void backtrack(int &ans, vector <string> &board, int col, int n){
        if(col == n){
            ans++;
            return;
        }
        for(int i = 0; i <n; i++){
            if(isValid(board,i,col)){
                board[i][col] = 'Q';
                backtrack(ans,board,col+1,n);
                board[i][col] = '.';
            }
        }
    }
    bool isValid(vector <string> &board, int row, int col){
        int n = board.size();
        for(int i = 1; i<=col; i++){
            if(board[row][col-i] == 'Q') return false;
        }
        for(int i = 1; row-i>=0 && col-i>=0; i++){
            if(board[row-i][col-i]== 'Q') return false;
        }
        for(int i = 1; row+i<n && col - i>=0; i++){
            if(board[row+i][col-i] == 'Q') return false;
        }
        return true;
    }
};