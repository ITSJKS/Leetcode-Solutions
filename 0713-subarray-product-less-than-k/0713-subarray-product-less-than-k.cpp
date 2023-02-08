class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long product = 1;
        long long count = 0;
        int l = 0;
        int n = nums.size();
        for(int r = 0; r < n; r++){
            product*=nums[r];
            while(product>=k && l <= r){
                product/=nums[l++];
            }
            if(product < k){
                int len = r - l + 1;
                count += len;
            } 
        }
        return count;
    }
};