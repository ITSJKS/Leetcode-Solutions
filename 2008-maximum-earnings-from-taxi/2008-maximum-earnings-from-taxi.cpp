class Solution {
public:
    long long dp[100001];
    long long solve(int idx, vector <vector <int>> &rides, vector <long long> &startTime){
        if(idx >= rides.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        auto next = lower_bound(startTime.begin()+idx+1,startTime.end(),rides[idx][1])-startTime.begin();
        long long take = rides[idx][1] - rides[idx][0] + rides[idx][2] + solve(next,rides,startTime);
        long long not_take = solve(idx+1,rides,startTime);
        return dp[idx] = max(take,not_take);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        memset(dp,-1,sizeof dp);
        vector <long long> startTime;
        sort(rides.begin(),rides.end());
        for(auto x:rides){
            startTime.push_back(x[0]);
        }
        return solve(0,rides,startTime);
    }
};