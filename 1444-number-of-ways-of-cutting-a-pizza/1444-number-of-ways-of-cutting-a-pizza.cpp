class Solution {
    long long mod = 1e9 + 7;
public:
    int dp[50][50][10];
    bool hasApple(vector <string> &pizza, int r, int re, int c, int ce){
        for(int i = r; i <= re; i++){
            for(int j = c; j <= ce; j++){
                if(pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }
    int solve(int srow, int scol, vector <string> &pizza, int k){
        if(k == 0) return 1;
        int n = pizza.size();
        int m = pizza[0].size();
        if(dp[srow][scol][k]!=-1) return dp[srow][scol][k];
        long long ans = 0;
        for(int row = srow; row < n-1; row++){
            // upper half
            bool upper = hasApple(pizza,srow,row,scol,m-1);
            // lowerhalf
            bool lower = hasApple(pizza,row+1,n-1,scol,m-1);
            if(upper && lower){
                ans = (ans + solve(row+1,scol,pizza,k-1))%mod;
            }
        }
        for(int col = scol; col < m-1; col++){
            bool left = hasApple(pizza,srow,n-1,scol,col);
            bool right = hasApple(pizza,srow,n-1,col+1,m-1);
            if(left && right){
                ans = (ans + solve(srow,col+1,pizza,k-1))%mod;
            }
        }
        return dp[srow][scol][k] = ans;
    }
    int ways(vector<string>& pizza, int k) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,pizza,k-1);
    }
};