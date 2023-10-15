class Solution {
public:
    int dp[501][501];
    int mod = 1e9 + 7;
    int solve(int ind, int cur, int len,int steps){
        if(cur < 0 || cur >= len) return 0;
        if(ind == steps) return cur == 0;
        if(dp[ind][cur]!=-1) return dp[ind][cur];
        int count = 0;
        count = (count + solve(ind+1,cur+1,len,steps))%mod;
        count = (count + solve(ind+1,cur,len,steps))%mod;
        count = (count + solve(ind+1,cur-1,len,steps))%mod;
        return  dp[ind][cur] = count;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,arrLen,steps);
    }
};

/*
We have a pointer at index 0
an array of size arrLen


*/