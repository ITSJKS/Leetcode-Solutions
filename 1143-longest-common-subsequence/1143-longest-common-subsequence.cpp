class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector <vector <int>> dp(n+1,vector <int>(m+1,0));
        for(int i = 1; i <=n; i++){
            for(int j = 1; j <=m; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

// either text1[i] match with text2[j] or not, if matching we can find maximum we can get from remaining string from both text1 and text2 else we can find maximum from substring text1 , text2[0:j-1] or vice versa