class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(x > sum) return -1;
        int find_sum = sum - x;
        int cur_sum = 0, left = 0, right = 0;
        int ans = -1;
        while(right <n){
            cur_sum += nums[right];
            while(cur_sum > find_sum && left <= right){
                cur_sum -= nums[left++];
            }
            if(cur_sum==find_sum) ans = max(ans,right - left+1);
            right++;
        }
        if(ans !=-1) return n - ans;
        return ans;
    }
};