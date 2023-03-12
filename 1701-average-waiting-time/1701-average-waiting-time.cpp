class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long cur = 0;
        long long wait = 0;
        for(auto x:customers){
            cur = max(cur,(long long)x[0]) + x[1];
            wait += cur - x[0];
        }
        return wait*1.0/(customers.size());
    }
};