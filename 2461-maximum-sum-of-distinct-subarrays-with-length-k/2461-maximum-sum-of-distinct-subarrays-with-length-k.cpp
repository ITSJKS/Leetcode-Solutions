class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map <int,int> mp;
        int n = nums.size();
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i <n; i++){
            if(i < k){
                sum += nums[i];
                mp[nums[i]]++;
            }
            else{
                mp[nums[i-k]]--;
                if(mp[nums[i-k]] == 0) mp.erase(nums[i-k]);
                sum -= nums[i-k];
                sum += nums[i];
                mp[nums[i]]++;
                
            }
            if(i>=k-1 && mp.size() == k) ans = max(ans,sum);
        }
        return ans;
    }
};