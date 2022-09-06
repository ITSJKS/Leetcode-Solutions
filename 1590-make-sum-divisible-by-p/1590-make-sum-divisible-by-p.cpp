class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(auto x:nums) sum += x;
        if(p > sum) return -1;
        else if(sum%p == 0) return 0;
        int cur = 0;
        int target = sum%p;
        unordered_map <int ,int > mp;
        mp[0] = -1;
        int n = nums.size();
        int res = n;
        for(int i = 0; i <n; i++){
            cur = (cur + nums[i])%p;
            int x = (cur%p - target+p)%p;
            mp[cur%p] = i;
            if(mp.find(x)!=mp.end()) res = min(res,i-mp[x]);
        }
        return res<n?res:-1;
    }
};