class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        vector <int> after(2*k+1,0);
        int n = prices.size();
        vector <int> cur(2*k+1,0);
        for(int ind = n-1; ind>=0; ind--){
            for(int trans = 2*k-1; trans>=0; trans--){
                if((trans&1) == 0){
                    cur[trans] = max(-prices[ind] + after[trans+1],after[trans]);
                }
                else{
                    cur[trans] = max(prices[ind] + after[trans+1],after[trans]);
                }
            }
            after = cur;
        }
        return after[0];
    }
};