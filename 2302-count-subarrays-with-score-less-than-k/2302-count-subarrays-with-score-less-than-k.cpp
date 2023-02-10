class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        int l = 0;
        long long  count = 0;
        for(int r = 0; r < nums.size(); r++){
            sum+=nums[r];
            while(sum*(r-l+1)>=k && l<=r){
                sum-=nums[l++];
            }
            count += r-l+1;
        }
        return count;
    }
};