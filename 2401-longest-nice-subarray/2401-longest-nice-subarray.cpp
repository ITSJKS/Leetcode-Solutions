class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int cur_and = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            while((cur_and & nums[r]) !=0){
                    cur_and ^= nums[l++];
            }
            cur_and  |= nums[r];
            maxi = max(maxi,r-l+1);         
        }
        return maxi;
    }
};