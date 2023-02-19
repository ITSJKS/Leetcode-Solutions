class Solution {
public:
    int dp[50001];
    int solve(int idx, vector <vector <int>> &jobs,vector <int> &j){
        if(idx >= jobs.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int not_take = solve(idx+1,jobs,j);
        int st = jobs[idx][0] , et = jobs[idx][1] , profit = jobs[idx][2];
        auto it = lower_bound(j.begin()+idx+1,j.end(),et) - j.begin();
        int take = profit + solve(it,jobs,j);
        return dp[idx] = max(take,not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        memset(dp,-1,sizeof dp);
        vector <vector <int>> jobs(n);
        for(int i = 0; i <n; i++){
            jobs[i] = {startTime[i],endTime[i],profit[i]};
        }
        sort(startTime.begin(),startTime.end());
        sort(jobs.begin(),jobs.end());
        return solve(0,jobs,startTime);
    }
};