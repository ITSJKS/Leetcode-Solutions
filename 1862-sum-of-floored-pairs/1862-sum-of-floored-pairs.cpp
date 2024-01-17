class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = nums.back();
        unordered_map <int,int> mp;
        for(auto &x:nums) mp[x]++;
        long long ans = 0;
        int mod = 1e9 + 7;
        for(auto &x:mp){
            int cur = 1;
            int num = x.first;
            while(num*1ll*cur <= maxi){
                long long r = num*(cur+1);
                long long l = num*(cur);
                ans = (ans + (mp[num]*1ll*(lower_bound(nums.begin(),nums.end(),r)-lower_bound(nums.begin(),nums.end(),l)))%mod*cur)%mod;
                cur++;
                cur%=mod;
                ans%=mod;
            }
        }
        return ans;
    }
};

// 100 
// 1 100 2 50 3 33 4 25 5 20
// nlogn(logn)
// nroot(n)logn
// suppose the number is nums[i] now we know that nums[i]/k is equal to 1 if nums[i] is greater than nums[i]/2 and less equal than nums[i]
// for a number nums[i]
// all values less than nums[i] can be used
// so for each value from i and j