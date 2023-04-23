class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int idx, string &s, int k,vector <int> &dp){
        int n = s.size();
        if(idx == n) return 1;
        if(idx > n) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long c = 0;
        for(int len = 1; len < 10 && len + idx <= n; len++){
            string t = s.substr(idx,len);
            long long num = stoll(t);
            if(num < 1 || num >k) break;
            c = (c+solve(idx+len,s,k,dp))%mod;
        }
        return dp[idx] = c;
    }
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector <int> dp(n+1,-1);
        return solve(0,s,k,dp);
    }
};