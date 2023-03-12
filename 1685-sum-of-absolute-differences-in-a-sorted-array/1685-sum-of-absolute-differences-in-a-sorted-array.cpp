class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector <int> prefix(nums.size());
        prefix[0] = nums[0];
        int n = nums.size();
        for(int i = 1; i <n; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        vector <int> ans(n);
        for(int i = 0; i <n; i++){
            int less_than = i;
            int greater_than  = n - i -1;
            ans[i] = (less_than)*nums[i] -(i>0?prefix[i-1]:0) + ((prefix[n-1] - prefix[i])  - greater_than*nums[i]);
        }
        return ans;
    }
};