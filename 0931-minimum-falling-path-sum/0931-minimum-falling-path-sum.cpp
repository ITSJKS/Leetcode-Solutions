class Solution {
public:
    int f(int i , int j, vector<vector<int>>& matrix,vector <vector <int>> &dp){
        if(j <0 || j >= matrix[0].size()) return 1e9;
        if(i == 0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = 1e9,left = 1e9,right = 1e9;
        up = matrix[i][j] + f(i-1,j,matrix,dp);
        left = matrix[i][j] + f(i-1,j-1,matrix,dp);
        right = matrix[i][j] + f(i-1,j+1,matrix,dp);
        return dp[i][j] =  min(up,min(left,right));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector <vector <int>> dp(n,vector <int> (m,-1));
        int best = 1e9;
        for(int j = 0; j<m; j++){
            best = min(best,f(n-1,j,matrix,dp));
        }
        return best;
    }
};