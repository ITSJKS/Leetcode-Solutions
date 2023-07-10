class Solution {
public:
    int dp[1025][41];
    int mod = 1e9 + 7;
    int solve(int mask , int ind, vector <vector <int>>&v,int n){
        if(mask == ((1<<n)-1)) return 1;
        if(ind == v.size()) return 0;
        if(dp[mask][ind]!=-1) return dp[mask][ind];
        long long count = 0;
        count = solve(mask,ind+1,v,n);
        for(auto &x:v[ind]){
            if(mask&(1<<x)) continue;
            int new_mask = mask | (1<<x);
            count = (count + solve(new_mask,ind+1,v,n))%mod;
        }
        return dp[mask][ind] = count;
    }
    int numberWays(vector<vector<int>>& hats) {
        vector <vector <int>> v(41);
        int n = hats.size();
        for(int i = 0; i <n; i++){
            for(auto &x:hats[i]) v[x].push_back(i);
        }
        memset(dp,-1,sizeof dp);
        int ans = solve(0,1,v,n);
        return ans;
    }
};