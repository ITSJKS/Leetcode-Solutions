class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int sum = 0 , count = 0;
        mp[0] = 1;
        for(auto &x:nums) sum += x, count += mp[sum-k],mp[sum]++;
        return count;
    }
};