class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        return mazeObstacles(og.size(),og[0].size(),og);
    }
    int solve(int m, int n,vector <vector <int>> &dp,vector <vector <int>> &mat){
    if(m>=0 && n>=0 && mat[m][n] == 1) return 0;
    if(m == 0 && n == 0) return 1;
    if(m<0 || n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    
    int f_top = solve(m-1,n,dp,mat);
    int f_left = solve(m,n-1,dp,mat);
    return dp[m][n] = (f_top + f_left);
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector <vector <int>> dp(n,vector <int> (m,-1));
    return solve(n-1,m-1,dp,mat);
}
};