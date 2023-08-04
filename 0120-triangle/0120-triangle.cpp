class Solution {
public:
    int dp[201][201];
    int solve(int i, int j, vector <vector <int>>&triangle){
        if(i < 0 || j < 0 || j >= triangle[i].size()) return 1e9;
        if(i == 0) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1e9;
        ans = min(ans,triangle[i][j] + solve(i-1,j,triangle));
        ans = min(ans,triangle[i][j] + solve(i-1,j-1,triangle));
        return dp[i][j] = ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        int ans = 1e9;
        memset(dp,-1,sizeof dp);
        for(int i = 0; i <m; i++){
            ans = min(ans,solve(n-1,i,triangle));
        }
        return ans;
    }
};