class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <vector <int>> dp(n+1,vector <int>(2,-1));
        return max_profit(prices,0,1,dp);
    }
    int max_profit(vector <int> &prices, int idx, bool buy,vector <vector <int>> &dp){
        if(idx >= prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            return dp[idx][buy] = max(-prices[idx]+max_profit(prices,idx+1,!buy,dp),max_profit(prices,idx+1,buy,dp));
        }
        else{
            return dp[idx][buy] = max(prices[idx]+max_profit(prices,idx+2,!buy,dp),max_profit(prices,idx+1,buy,dp));
        }
    }
};