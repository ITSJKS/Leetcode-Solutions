class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = first_occur(nums,target);
        int last = last_occur(nums,target);
        vector <int> ans = {first,last};
        return ans;
    }
    int first_occur(vector <int> &nums, int target){
        int l = 0, h = nums.size()-1;
        int res = -1;
        while(l<=h){
            int mid = l+ (h-l)/2;
            if(nums[mid]==target){
                res = mid;
                h = mid - 1;
            }
            else if(nums[mid]>target)
                h = mid - 1;
            else{
                l = mid + 1;
            }
        }
        return res;
    }
    int last_occur(vector <int> &nums, int target){
        int l = 0, h = nums.size()-1;
        int res = -1;
        while(l<=h){
            int mid = l+ (h-l)/2;
            if(nums[mid]==target){
                res = mid;
                l = mid + 1;
            }
            else if(nums[mid]>target){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return res;
    }
};