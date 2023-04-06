class Solution {
public:
    vector <int> dr = {-1,0,1,0};
    vector <int> dc = {0,1,0,-1};
    bool dfs(int i, int j, vector <vector <int>> &grid,vector <vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        if(i <0 || i >=n || j <0 || j >= m) return false;
        if(grid[i][j] == 1 || vis[i][j]) return true;
        vis[i][j] = 1;
        bool check = true;
        for(int k = 0; k < 4; k++){
            int di = i + dr[k];
            int dj = j + dc[k];
            if(!dfs(di,dj,grid,vis)) check = false;
        }
        return check;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector <vector <int>> vis(n,vector <int>(m,0));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    count += (dfs(i,j,grid,vis));
                }
            }
        }
        return count;
    }
};