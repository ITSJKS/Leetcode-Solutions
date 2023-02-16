class Solution {
public:

    int solve(int idx, int count,vector <int> &s, int &n,vector <vector <int>> &dp){
        if(idx >= n ) return 0;
        if(dp[idx][count]!=-1) return dp[idx][count];
        int take = 0;
        take = max(take,s[idx]*count + solve(idx+1,count+1,s,n,dp));   
        int not_take = solve(idx+1,count,s,n,dp);
        return dp[idx][count] = max(take,not_take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector <vector<int>> dp(n+1,vector <int>(n+1,-1));
        return solve(0,1,satisfaction,n,dp);
    }
};