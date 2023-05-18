class Solution {
public:
    int mod = 1e9 + 7;
    int dp[5001][4][4][4];
    int solve(int ind , int c1, int c2, int c3, int n){
        if(ind == n) return 1;
        if(ind >n) return 0;
        if(dp[ind][c1][c2][c3]!=-1) return dp[ind][c1][c2][c3];
        int count = 0;
        // col0
        for(int a = 1; a <=3; a++){
            if(a == c1) continue;
            for(int b = 1;  b<=3; b++){
                if(b == c2 || b == a) continue;
                for(int c = 1; c <=3; c++){
                    if(c == c3 || c == b) continue;
                    count = (count + solve(ind+1,a,b,c,n))%mod;
                }
            }
        }
        return dp[ind][c1][c2][c3] = count;
    }
    int numOfWays(int n) {
       memset(dp,-1,sizeof dp);
       return solve(0,0,0,0,n);
    }
};