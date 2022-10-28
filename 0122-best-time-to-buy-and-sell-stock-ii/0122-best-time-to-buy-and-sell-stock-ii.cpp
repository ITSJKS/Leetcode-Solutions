class Solution {
public:
    int maxProfit(vector<int>& values) {
    int n = values.size();
    long long aheadBuy, aheadNotBuy, curBuy, curNotBuy ;
    aheadBuy = aheadNotBuy =  curBuy = curNotBuy  = 0;
    for(int i = n-1; i >=0; i--){
        curBuy = max(-values[i] + aheadNotBuy,aheadBuy);
        curNotBuy = max(values[i] + aheadBuy, aheadNotBuy);
        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }
    return aheadBuy;
    }
};