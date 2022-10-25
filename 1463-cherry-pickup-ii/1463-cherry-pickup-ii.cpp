class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        return mc(grid.size(),grid[0].size(),grid);
    }
int solve(int i, int j1, int j2, vector <vector <int>> &grid,vector <vector <vector <int>>> &dp){
    if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) return -1e8;
    if(i == grid.size()-1){
        if(j1 == j2) return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int best = -1e8;
    for(int k = -1; k <=1; k++){
        for(int j = -1; j <=1; j++){
            int value = 0;
            if(j1 == j2) value += grid[i][j1];
            else value += grid[i][j1] + grid[i][j2];
            value += solve(i+1,j1+k, j2+j,grid,dp);
            best = max(value,best);
        }
    }
    return dp[i][j1][j2] = best;
    
}
int mc(int r, int c, vector<vector<int>> &grid) {
    vector <vector <vector <int>>> dp(r,vector  <vector <int>>(c,vector <int>(c,-1)));
   return  solve(0,0,c-1,grid,dp);
}
};