class Solution {
public:
    static const int N = 1e5 + 1;
    long long dp[N];
    long long solve(int idx, vector <vector <int>> &q){
        if(idx >= q.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long ans = 0;
        long long pt = q[idx][0] , day = q[idx][1];
        // take
        ans = max(ans,pt + solve(idx+day+1,q));
        // notTake
        ans = max(ans,solve(idx+1,q));
        return dp[idx] = ans;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof dp);
        return solve(0,questions);
    }
};