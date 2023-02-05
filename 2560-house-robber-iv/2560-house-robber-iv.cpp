class Solution {
public:
    bool check(vector <int> &nums, int mid, int k){
        int count = 0;
        int n = nums.size();
        for(int i = 0; i <n; i++){
            if(nums[i] <= mid) count++,i++;
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = 0, r = 1e9+1;
        while(r - l>1){
            int mid = l + (r-l)/2;
            if(check(nums,mid,k)) r = mid;
            else l = mid;
        }
        return r;
    }
};