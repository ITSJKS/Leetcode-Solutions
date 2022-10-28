class Solution {
public:
    int maxProfit(vector<int>& values) {
    int n = values.size();
    vector <long long> ahead(2,0);
    for(int i = n-1; i >=0; i--){
        for(int buy = 1; buy >=0; buy--){
            if(buy){
                ahead[buy] = max(-values[i] + ahead[!buy],ahead[buy]);
            }
            else{
                ahead[buy] = max(values[i] + ahead[!buy], ahead[buy]);
            }
        }
    }
    return ahead[1];
    }
};