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
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin(),s.end());
        vector <vector<int>> dp(n+1,vector <int>(n+2,0));
        for(int idx = n-1; idx >=0; idx--){
            for(int count = 1; count <=n; count++){
                int take = 0;
                take = max(take,s[idx]*count + dp[idx+1][count+1]);
                int not_take = dp[idx+1][count];
                dp[idx][count] = max(take,not_take);
            }
        }
        return dp[0][1];
    }
};