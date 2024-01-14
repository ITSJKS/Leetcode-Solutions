class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,int> mp;
        for(int i = 0; i <n; i++){
            mp[nums[i]]= i;
        }
        long long ans = n;
        sort(nums.begin(),nums.end());
        for(int i = 1; i <n; i++){
            if(mp[nums[i]] < mp[nums[i-1]]){
                ans += n-i;
            }
        }
        return ans;
    }
};

// 3 4 -1 3 4 -1
// 2 + 