class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map <int,int> mp;
        int count = 0;
        for(auto &x:nums) mp[x]++;
        for(auto &x:mp){
            if(x.second == 1) return -1;
            count += (x.second+2)/3;
        }
        return count;
    }
};