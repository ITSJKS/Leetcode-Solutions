class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i <n; i++){
            long long lc_m = nums[i];
            for(int j = i; j <n; j++){
                if(lc_m > k) break;
                lc_m = lcm(lc_m,(long long)nums[j]);
                if(lc_m == k) count++;
            }
        }
        return count;
    }
};