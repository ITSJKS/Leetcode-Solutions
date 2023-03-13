class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int start = -1;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i <n; i++){
            if(start == -1){
                start = nums[i];
                count++;
            }
            if(nums[i] - start > k){
                count++;
                start = nums[i];
            }
        }
        return count;
    }
};