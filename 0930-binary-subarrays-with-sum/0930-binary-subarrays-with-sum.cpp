class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map <int,int> mp;
        mp[0] = 1;
        int cur_sum = 0;
        int count=  0;
        for(int i = 0; i <nums.size(); i++){
            cur_sum += nums[i];
            if(mp.find(cur_sum - goal)!=mp.end()){
                count += mp[cur_sum-goal];
            }
            mp[cur_sum]++;
        }
        return count;
    }
};