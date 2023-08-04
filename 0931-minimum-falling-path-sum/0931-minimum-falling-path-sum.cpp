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
        vector <vector <int>> dp(n,vector <int> (m,1e9));
        // int best = 1e9;
        // for(int j = 0; j<m; j++){
        //     best = min(best,f(n-1,j,matrix,dp));
        // }
        // return best;
        for(int i = 0; i <n; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i <n; i++){
            for(int j = 0; j <n; j++){
                int cur = 1e9;
                if(i > 0 && j+1 < n) cur = min(cur,dp[i-1][j+1]);
                if(i > 0 && j > 0) cur = min(cur, dp[i-1][j-1]);
                if(i > 0) cur = min(cur,dp[i-1][j]);
                dp[i][j] = matrix[i][j] + cur;
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};