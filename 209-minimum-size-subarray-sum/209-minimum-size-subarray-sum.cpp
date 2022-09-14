class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int l = 0,j = 0;
       int n = nums.size();
       int len = INT_MAX;
       int sum = 0;
       while(j<n){
           sum += nums[j++];
           while(sum>=target){
               len = min(len,j-l);
               sum-=nums[l++];
           }
       }
        return len==INT_MAX?0:len;
    }
};