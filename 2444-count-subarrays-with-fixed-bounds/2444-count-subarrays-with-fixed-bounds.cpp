class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long j = 0, min_idx = -1, max_idx = -1,res = 0;
        int n = nums.size();
        for(int i = 0; i <n; i++){
            if(nums[i]<minK || nums[i]>maxK){
                min_idx = -1;
                max_idx = -1;
                j = i+ 1;
            }
            else{
                if(nums[i] == minK) min_idx = i;
                if(nums[i] == maxK) max_idx = i;
            }
            res += max(0LL,min(min_idx,max_idx) -j + 1 );
        }
        return res;
    }
};