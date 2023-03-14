class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
        long long cur_sum = 0;
        int n = nums.size();
        for(int i = 0; i <n-1; i++){
            int x = nums[i];
            cur_sum += x;
            if(cur_sum >= (sum - cur_sum)) count++;
        }
        return count;
    }
};