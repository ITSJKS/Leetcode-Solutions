class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset <int> m;
        int l = 0, r= 0 , n = nums.size();
        for(; r < n; r++){
            m.insert(nums[r]);
            if(*m.rbegin() - *m.begin() > limit) m.erase(m.find(nums[l++]));
        }
        return r - l;
    }
};