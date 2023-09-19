class Solution {
public:
    int mod = 1e9 + 7;
    int n;
    int dp[10001][7][7];
    int solve(int ind, int prev1, int prev2){
        if(ind >= n) return 1;
        if(dp[ind][prev1][prev2]!=-1) return dp[ind][prev1][prev2];
        long long count = 0;
        for(int j = 0; j <6; j++){
            if(j!= prev1 && j!= prev2 && gcd(prev1+1,j+1) == 1){
                count =  (count + solve(ind+1,j,prev1))%mod;
            }
        }
        return dp[ind][prev1][prev2] = count;
    }
    int distinctSequences(int n_) {
        n = n_;
        memset(dp,-1,sizeof dp);
        return solve(0,6,6);
    }
};
// 10000 * 6 *6