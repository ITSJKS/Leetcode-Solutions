class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int count = 0, ans = 0;
        for(auto x:nums){
            if(x == maxi) count++;
            else count = 0;
            ans = max(count,ans);
        }
        return ans;
    }
};