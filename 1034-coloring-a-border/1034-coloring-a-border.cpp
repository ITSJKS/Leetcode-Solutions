class Solution {
public:
    vector  <int> dx = {-1,0,1,0};
    vector <int> dy = {0,-1,0,1};
    int c;
    set <pair <int,int>> vis;
    bool isValid(int nrow, int ncol, int n, int m){
        return nrow>=0 && nrow < n && ncol >= 0 && ncol < m;
    }
        bool dfs(int row, int col,int color,vector <vector <int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if(vis.count({row,col})) return true;
        if(!(isValid(row,col,n,m) && grid[row][col] == c)) return false;
        int prev = grid[row][col];
        int cnt = 0;
        vis.insert({row,col});
        for(int i = 0; i <4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            cnt += dfs(nrow,ncol,color,grid);
        }
        if(cnt < 4){
            grid[row][col] = color;
        }
        return true;
       
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        c = grid[row][col];
        dfs(row,col,color,grid);
        return grid;
    }
};