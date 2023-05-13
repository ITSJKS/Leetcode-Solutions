int mod = 1e9 + 7;
int dp[100001];
class Solution {
public:
    int solve(int idx, int low , int high , int zero, int one){
        if(idx > high) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int count = 0;
        if(idx >= low && idx <= high ){
            count = (count + 1)%mod;
        }
        count = (count + solve(idx+zero, low, high , zero, one))%mod;
        count = (count + solve(idx + one, low , high , zero , one))%mod;
        return dp[idx] = count;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof dp);
        int count = 0;
        count  = (count + solve(one,low,high,zero,one))%mod;
        count = (count + solve(zero,low,high,zero, one))%mod;
        return count;
    }
};