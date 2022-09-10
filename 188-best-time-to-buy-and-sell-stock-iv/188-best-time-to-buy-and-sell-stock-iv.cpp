class Solution {
    int dp[1001][100][2];
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k>2*prices.size()){
            int res = 0;
            for(int i = 1;i<prices.size(); i+=2){
                res += max(0,prices[i]-prices[i-1]);
            }
            return res;
        }
        memset(dp,-1,sizeof(dp));
        return find_profit(prices,0,0,k,1);
    }
    int find_profit(vector <int> &prices, int idx, int t, int k, bool buy){
        if(idx == prices.size() || t >= k) return 0;
        if(dp[idx][t][buy]!=-1) return dp[idx][t][buy];
        if(buy){
            return dp[idx][t][buy] = max(-prices[idx]+find_profit(prices,idx+1,t,k,!buy),find_profit(prices,idx+1,t,k,buy));
        }
        else{
            return dp[idx][t][buy] = max(prices[idx]+find_profit(prices,idx+1,t+1,k,!buy),find_profit(prices,idx+1,t,k,buy));
        }
    }
};