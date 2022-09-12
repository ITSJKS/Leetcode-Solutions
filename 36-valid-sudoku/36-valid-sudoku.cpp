class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector <set <int>> row(9),col(9),subgrid(9);
        for(int i = 0; i <9; i++){
            for(int j =0; j <9; j++){
                if(board[i][j]=='.') continue;
                int num = board[i][j]-'0';
                if(row[i].count(num) || col[j].count(num)|| subgrid[((i/3)*3+j/3)].count(num)) return false;
                row[i].insert(num);
                col[j].insert(num);
                subgrid[(i/3)*3+j/3].insert(num);
            }
        }
        return true;
    }
};