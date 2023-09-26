class Solution {
public:
    int dp[101][102];
    int solve(int ind ,int prev,vector <vector <int>>&cuboids){
        int n = cuboids.size();
        if(ind == n) return 0;
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        // skip the current one
        int ans = 0;
        ans = max(ans,solve(ind+1,prev,cuboids));
        if(prev == n || (cuboids[ind][0] >= cuboids[prev][0] && cuboids[ind][1] >= cuboids[prev][1] && cuboids[ind][2] >= cuboids[prev][2])){
            ans = max(ans, cuboids[ind][2] + solve(ind+1,ind,cuboids));
        }
        return dp[ind][prev]= ans;
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &x:cuboids){
            sort(x.begin(),x.end());
        }
        sort(cuboids.begin(),cuboids.end());
        int n = cuboids.size();
        memset(dp,-1,sizeof dp);
        return solve(0,n,cuboids);
    }
};