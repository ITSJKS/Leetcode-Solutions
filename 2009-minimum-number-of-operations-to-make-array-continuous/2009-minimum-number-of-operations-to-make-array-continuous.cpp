class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end());
        auto it = unique(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),it));
        int n = nums.size();
        int ans = size;
        for(int r = 0, l = 0; r < n; r++){
            while(nums[l] < nums[r] - (size-1)){
                l++;
            }
            ans = min(ans,size-r+l-1);
        }
        return ans;
    }
};