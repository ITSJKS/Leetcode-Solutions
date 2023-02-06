class Solution {
public:
    int check(int mid, vector <int> &nums, int target){
        int sum = 0;
        // cout<<mid<<" ";
        for(int i = 0; i <mid; i++){
            sum += nums[i];
            if(sum >=target) return true;
        }
        for(int i = mid; i<nums.size(); i++){
            sum-=nums[i-mid];
            sum+=nums[i];
            if(sum>=target) return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid,nums,target)) r = mid;
            else l = mid;
        }
        if(r == n+1) return 0;
        return r;
    }
};