class Solution {
public:
    void dfs(int i, int j, vector <vector <int>>&board,vector <vector <int>>&vis){
        vis[i][j] = 1;
        int n = board.size();
        int m = board[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int k = 0; k <4; k++){
            int row = i + dx[k];
            int col = j + dy[k];
            if(row >=0 && row <n && col >=0 && col<m && !vis[row][col] && board[i][j] == 1){
                dfs(row,col,board,vis);
            }
        }
        
    }
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector <vector <int>> vis(m,vector <int>(n,0));
        for(int i = 0; i <n; i++){
                //first row
                if(!vis[0][i] && board[0][i] == 1){
                    dfs(0,i,board,vis);
                }
                //last row
                if(!vis[m-1][i]&& board[m-1][i] == 1){
                    dfs(m-1,i,board,vis);
                }
            }
            for(int i = 0; i <m; i++){
                //first col
                if(!vis[i][0]&& board[i][0] == 1){
                    dfs(i,0,board,vis);
                }
                //last col
                if(!vis[i][n-1]&& board[i][n-1] == 1){
                    dfs(i,n-1,board,vis);
                }
            }
        int count = 0 ;
        for(int i = 0; i <m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 1 && vis[i][j] != 1){
                    count++;
                }
            }
        }
        return count;
    }
};