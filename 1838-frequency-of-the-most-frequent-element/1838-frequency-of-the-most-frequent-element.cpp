class Solution {
public:
    bool check(int mid, vector <int> &nums, int k){
        long long sum = 0;
        for(int i = 0; i <mid; i++){
            sum += nums[i];
        }
        long long diff = nums[mid-1]*1ll*mid - sum;
        if(diff <= k) return true;
        for(int i = mid; i<nums.size(); i++){
            sum -= nums[i-mid];
            sum += nums[i];
            long long diff = nums[i]*1ll*mid - sum;
            if(diff <= k) return true;
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0, r = n+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid,nums,k)) l = mid;
            else r = mid;
        }
        return l;
    }
};