class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector <pair <int,int>> diff_profit;
        for(int i = 0; i <difficulty.size(); i++){
            diff_profit.push_back({difficulty[i],profit[i]});
        }
        sort(diff_profit.begin(),diff_profit.end());
        sort(worker.begin(),worker.end());
        long long sum = 0;
        int i = 0;
        int best = 0;
        for(auto x:worker){
            while( i  < n && diff_profit[i].first <= x ){
                best  = max(best,diff_profit[i++].second);
            }
            sum += best;
        }
        return sum;
    }
};