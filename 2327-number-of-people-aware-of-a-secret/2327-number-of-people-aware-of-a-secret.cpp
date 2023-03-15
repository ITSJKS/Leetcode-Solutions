class Solution {
public:
    int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector <long long> dp(n);
        dp[0] = 1;
        for(int i = 0; i <n; i++){
            for(int j = i + delay ; j < i + forget &&  j <n ; j++){
                dp[j]= (dp[j] + dp[i])%mod;
            }
        }
        long long ans = 0;
        for(int i = n-forget; i<n; i++){
            ans = (ans + dp[i])%mod;
        }
        return ans;
    }
};