class Solution {
public:
    int rev(int num){
        string a = to_string(num);
        reverse(a.begin(),a.end());
        return stoi(a);
    }
    int mod = 1e9 + 7;
    int countNicePairs(vector<int>& nums) {
        long long  count = 0;
        unordered_map <int,int> mp;
        for(auto x:nums){
            int y = rev(x);
            count = (count + mp[x-y])%mod;
            mp[x-y]++;
        }
        return count;
    }
};