class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map <int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        int ans = -1;
        int count = -1;
        for(auto x:mp){
            if(x.first%2 == 0 && x.second>count){
                count = x.second;
                ans = x.first;
            }
        }
        return ans;
    }
};