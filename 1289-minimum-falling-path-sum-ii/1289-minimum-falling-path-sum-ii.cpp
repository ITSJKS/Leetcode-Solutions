class Solution {
public:
   int dp[201][201];
    int solve(int i, int j, vector <vector <int>>&grid){
        if(i == grid.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1e9;
        for(int k = 0; k <grid[0].size(); k++){
            if(k == j) continue;
            ans = min(ans,grid[i][k] + solve(i+1,k,grid));
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int ans = 1e9;
        memset(dp,-1,sizeof dp);
        ans = min(ans,solve(0,m,grid));
        return ans;
    }
};