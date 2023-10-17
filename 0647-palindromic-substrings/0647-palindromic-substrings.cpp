class Solution {
public:
    int solve(int i, int j, string &s,vector <vector <int>> &dp){
    if(i == j) return true;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 0;
    if(j - i == 1) ans = s[i] == s[j];
    else ans = (s[i] == s[j]) && solve(i+1,j-1,s,dp);
    return dp[i][j] = ans;
}
    int countSubstrings(string s) {
        int n = s.size();
        vector <vector <int>> dp(n,vector <int>(n,-1));
        int count = 0;
        for(int i = 0; i <n; i++){
        for(int j = i; j <n; j++){
            if(solve(i,j,s,dp)) count++;
        }
    }
        return count;
    }
};