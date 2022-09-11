class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector <vector <int>> dp(n+1,vector <int>(2,-1));
        return max_profit(prices,0,1,fee,dp);
    }
    int max_profit(vector <int> &prices, int idx, bool buy, int fee,vector <vector <int>> &dp){
        if(idx == prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            return dp[idx][buy] = max(-prices[idx]+max_profit(prices,idx+1,!buy,fee,dp),max_profit(prices,idx+1,buy,fee,dp));
        }
        else{
            return dp[idx][buy] = max(prices[idx]-fee+max_profit(prices,idx+1,!buy,fee,dp),max_profit(prices,idx+1,buy,fee,dp));
        }
    }
};