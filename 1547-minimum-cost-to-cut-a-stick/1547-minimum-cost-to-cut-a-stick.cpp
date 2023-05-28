class Solution {
public:
    int f(int i, int j, vector <int> &cuts,vector <vector <int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e8;
        for(int k = i; k <=j; k++){
            mini = min(mini, cuts[j+1] - cuts[i-1] + f(i,k-1,cuts,dp) + f(k+1,j,cuts,dp));
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector <vector <int>> dp(c+2, vector <int>(c+2,0));
        for(int i = c; i >=1; i--){
            for(int j = i; j<=c; j++){
                int mini = 1e8;
        for(int k = i; k <=j; k++){
            mini = min(mini, cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j]);
        }
        dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};