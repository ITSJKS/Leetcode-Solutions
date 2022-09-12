class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <bool> visited(366,false);
        vector <int> dp(366,-1);
        for(auto x:days) visited[x] = true;
        return solve(0,visited,costs,dp);
    }
    int solve(int idx, vector <bool> &visited, vector <int> &costs,vector <int> &dp){
        if(idx >= 366) return 0;
        if(dp[idx]!=-1) return dp[idx];
        if(!visited[idx]) return solve(idx+1,visited,costs,dp);
        int one_day_pass = costs[0] + solve(idx+1,visited,costs,dp);
        int one_week_pass = costs[1] + solve(idx+7,visited,costs,dp);
        int one_month_pass = costs[2] + solve(idx+30, visited,costs,dp);
        return dp[idx] = min({one_day_pass,one_week_pass,one_month_pass});
    }
};