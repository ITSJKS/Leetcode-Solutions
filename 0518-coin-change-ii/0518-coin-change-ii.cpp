class Solution {
public:
    int dp[300][5001];
    int solve(int ind,int amount,vector <int>&coins){
        if(ind == coins.size()) return amount == 0;
        if(amount == 0) return 1;
        else if(amount < 0) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        return dp[ind][amount] = solve(ind,amount-coins[ind],coins) + solve(ind+1,amount,coins);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
        return solve(0,amount,coins);
    }
};