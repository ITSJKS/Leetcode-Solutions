class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // we can implement the atmost(k) - atmost(k-1)
        // basic sliding window 
        //[0 0 0 1 0 0 0 1 0 0 0]
        for(auto &x:nums){
            x = x%2;
        }
        int sum = 0;
        int ans = 0;
        unordered_map <int,int> mp;
        mp[0] = 1;
        for(auto x:nums){
            sum +=x;
            ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};