class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map <long long,long long> mp;
        long long n = nums.size();
        long long count = 0;
        for(long long i = 0; i<n; i++){
            count += mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        return n*(n-1)/2-count;
    }
};