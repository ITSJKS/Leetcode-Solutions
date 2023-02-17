class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector <int> prefix(n,0);
        for(int i = 0; i <n; i++){
            if(i == 0) prefix[i] = nums[i];
            else prefix[i] = prefix[i-1] + nums[i];
        }
        int mod = 1e9 +7;
        long long ans = 0;
        for(int i = 0; i <n; i++){
            int left_sum = prefix[i];
            int mid_sum_l = 2*prefix[i];
            int mid_sum_r = (prefix[n-1] + prefix[i])/2;
            int l = lower_bound(prefix.begin()+i+1,prefix.end(),mid_sum_l) - prefix.begin();
            int r = upper_bound(prefix.begin()+i+1,prefix.begin()+n-1,mid_sum_r) - prefix.begin();
            r--;
            int count = r - l + 1;
            ans = (ans + max(0,count))%mod;
        }
        return ans%mod;
    }
};