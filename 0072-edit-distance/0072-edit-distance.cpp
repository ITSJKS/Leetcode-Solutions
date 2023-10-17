class Solution {
public:
    int dp[501][501];
    int solve(int ind1, int ind2, string &word1, string &word2){
        if(ind1 < 0) return ind2 + 1;
        if(ind2 < 0) return ind1 + 1;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(word1[ind1] == word2[ind2]) return dp[ind1][ind2] = solve(ind1-1,ind2-1,word1,word2);
        else return dp[ind1][ind2] =  min({1 + solve(ind1-1,ind2-1,word1,word2),solve(ind1,ind2-1,word1,word2)+1,1+solve(ind1-1,ind2,word1,word2)});
        
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memset(dp,-1,sizeof dp);
        return solve(n-1,m-1,word1,word2);
    }
};