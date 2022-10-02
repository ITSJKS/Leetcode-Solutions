class Solution {
    int mod = 1e9+7;
    int dp[32][1001];
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return find_ans(n,k,target);
    }
    int find_ans(int n,int k,int target){
        if(target == 0 && n == 0){
            return 1;
        }
        if(n<=0) return 0;
        if(target <= 0 ) return 0;
        if(dp[n][target] !=-1) return dp[n][target];
        
        int count = 0;
        for(int j = 1; j <=k; j++){
            count = (count%mod+ find_ans(n-1,k,target-j))%mod;
        }
        return dp[n][target] = count;
    }
};