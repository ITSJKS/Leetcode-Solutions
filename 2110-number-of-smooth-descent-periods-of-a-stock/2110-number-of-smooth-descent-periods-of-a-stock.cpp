class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long count = 0;
        long long temp = 0;
        for(int r =0; r<n; r++){
            if(r == 0 || prices[r]==prices[r-1]-1){
                temp++;
                count += temp;
            }
            else{
                count++;
                temp = 1;
            }
        }
        return count;
    }
};