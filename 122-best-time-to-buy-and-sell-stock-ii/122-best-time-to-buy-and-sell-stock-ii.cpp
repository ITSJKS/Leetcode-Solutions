class Solution {
    int dp[30001][2];
public:
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return find_profit(prices,0,1);
    }
    int find_profit(vector <int> &prices, int idx, bool buy){
        if(idx == prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
           return dp[idx][buy] = max(-prices[idx]+find_profit(prices,idx+1,!buy),find_profit(prices,idx+1,buy)); 
        }
        else{
            return dp[idx][buy] = max(prices[idx]+find_profit(prices,idx+1,!buy),find_profit(prices,idx+1,buy));
        }
        return 0;
    }
};