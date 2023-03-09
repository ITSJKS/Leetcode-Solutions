class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector <int> suffix(n);
        suffix[n-1] = (nums[n-1] == 1);
        int longest = 0;
        for(int i = n-2; i >=0; i--){
            if(nums[i] == 1) suffix[i] = suffix[i+1]+1;
            else suffix[i] = 0;
            longest = suffix[i+1];
        }
        int cur_1 = 0;
        for(int i = 0; i <n-1; i++){
            longest = max(longest,cur_1 + suffix[i+1]);
            if(nums[i] == 1)
                cur_1 += 1;
            else cur_1 = 0;
        }
        return longest;
    }
};