class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        if(h==0) return nums[h];
        if(nums[0]!=nums[1]) return nums[0];
        while(l<=h){
            int mid =  l + (h-l)/2;
            int k = mid%2==0 ? mid + 1:mid -1;
            if(nums[k]!=nums[mid]) h = mid - 1;
            else l =  mid + 1;
            }
        return nums[l];
    }
};