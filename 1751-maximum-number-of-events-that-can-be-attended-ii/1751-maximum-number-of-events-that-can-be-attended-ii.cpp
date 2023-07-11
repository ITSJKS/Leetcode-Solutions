class Solution {
public:
    int solve(int ind, int k, vector <vector <int>>&events,vector <int>&v,vector <vector <int>>&dp){
        if(ind >= events.size()) return 0;
        if(k == 0) return 0;
        if(dp[ind][k]!=-1) return dp[ind][k];
        int cost = 0;
        // skip it
        cost = max(cost,solve(ind+1,k,events,v,dp));
        auto it = upper_bound(v.begin()+ind+1,v.end(),events[ind][1])-v.begin();
        cost = max(cost,events[ind][2] + solve(it,k-1,events,v,dp));
        return dp[ind][k] = cost;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        auto cmp = [&](vector <int>&a, vector <int>&b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        };
        sort(events.begin(),events.end(),cmp);
        // for(auto &x:events) cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
        vector <int> v;
        for(auto &x:events) v.push_back(x[0]);
        int n = v.size();
        vector <vector <int>>dp(n+1,vector <int>(k+1,-1));
        return solve(0,k,events,v,dp);
    }
};