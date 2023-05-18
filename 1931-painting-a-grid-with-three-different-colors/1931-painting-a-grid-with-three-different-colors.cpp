class Solution {
public:
    // I am gonna create the worst solution ever
    int mod = 1e9 + 7;
    int dp[1001][4][4][4][4][4];
    int solve(int ind , int c1, int c2, int c3,int c4, int c5,int n,int m){
        if(ind == n) return 1;
        if(ind >n) return 0;
        if(dp[ind][c1][c2][c3][c4][c5]!=-1) return dp[ind][c1][c2][c3][c4][c5];
        int count = 0;
        // col0
        for(int a = 1; a <=3; a++){
            if(a == c1) continue;
            if(m == 1){
                count = (count + solve(ind+1,a,c2,c3,c4,c5,n,m))%mod;
                continue;
            }
            for(int b = 1;  b<=3; b++){
                if(b == c2 || b == a) continue;
                if(m == 2){
                    count = (count + solve(ind+1,a,b,c3,c4,c5,n,m))%mod;
                    continue;
                }
                for(int c = 1; c <=3; c++){
                    if(c == c3 || c == b) continue;
                    if(m == 3){
                    count = (count + solve(ind+1,a,b,c,c4,c5,n,m))%mod;
                    continue;
                }
                    for(int d = 1; d <=3; d++){
                        if(d == c4 || d == c) continue;
                        if(m == 4){
                    count = (count + solve(ind+1,a,b,c,d,c5,n,m))%mod;
                    continue;
                }
                        for(int e = 1; e <=3; e++){
                            if(e == c5 || e == d) continue;
                                count = (count + solve(ind+1,a,b,c,d,e,n,m))%mod;
                        }
                    }
                }
            }
        }
        return dp[ind][c1][c2][c3][c4][c5] = count;
    }
    int colorTheGrid(int m, int n) {
        memset(dp,-1,sizeof dp);
       return solve(0,0,0,0,0,0,n,m);
    }
};