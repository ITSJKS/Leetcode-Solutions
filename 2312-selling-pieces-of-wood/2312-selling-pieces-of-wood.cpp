class Solution {
public:
    long long dp[201][201];
    long long solve(int m, int n, map <pair<int,int>,int>&mp){
        if(m <= 0 || n <= 0) return 0;
        if(m == 1 && n == 1){
            if(mp.count({m,n})) return mp[{m,n}];
            return 0;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        long long res = 0;
        if(mp.count({m,n})) res = mp[{m,n}];
        for(int j = 1; j <=m-1; j++){
            int left = m - j;
            res = max(res,solve(j,n,mp) + solve(left,n,mp));
        }
        for(int j = 1; j <=n-1; j++){
            int left = n - j;
            res = max(res,solve(m,j,mp) + solve(m,left,mp));
        }
        return dp[m][n] = res;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        map <pair<int,int>,int> mp;
        for(auto &x:prices){
            mp[{x[0],x[1]}] = x[2];
        }
        memset(dp,-1,sizeof dp);
        return solve(m,n,mp);
    }
};