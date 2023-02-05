class Solution {
public:
    bool check(int max_w,vector <int> &weights,int days){
        int day_needed = 1;
        int load = 0;
        for(auto x:weights){
            load += x;
            if(load > max_w){
                day_needed++;
                load = x;
            }
        }
        return day_needed <= days;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int high = accumulate(weights.begin(),weights.end(),0)+1;
        int low = *max_element(weights.begin(),weights.end())-1;
        while(high- low > 1){
            int mid = low + (high-low)/2;
            if(check(mid,weights,days)){
                high = mid;
            }
            else{
                low = mid;
            }
        }
        return high;
    }
};