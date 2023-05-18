class Solution {
public:
    int mod = 1e9 + 7;
    int dp[51][101][51];
    int solve(int i, int maxi, int n, int m, int k){
        if(i == n){
            if(k == 0) return 1;
            return 0;
        }
        if(k < 0) return 0;
        if(dp[i][maxi][k]!=-1) return dp[i][maxi][k];
        int count = 0;
        for(int num = 1; num <=m; num++){
            count = (count + solve(i+1, max(maxi,num), n,m,k - (maxi < num)))%mod;
        }
        return dp[i][maxi][k] = count;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,n,m,k);
    }
};