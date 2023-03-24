class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(nums.size() <= 4) return 0;
        int i = 3, j = n-1;
        int count = 0;
        int ans = INT_MAX;
        while(i>=0 && j>=0){
            ans = min(ans,nums[j]- nums[i]);
            j--;
            i--;
        }
        return ans;
    }
};