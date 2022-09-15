class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int count1 = 1;
        int count2 = 1;
        int n = nums.size();
        for(int i = 1; i <n; i++){
            if(nums[i]<nums[i-1]) count1 = count2+1;
            else if(nums[i]>nums[i-1]) count2 = count1+1;
        }
        return min(n,max(count1,count2));
    }
};