class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int c = 0;
        long long count = 0;
        set <int> st(nums.begin(),nums.end());
        for(auto &x:st){
            int cnt = __builtin_popcount(x);
            c += (2*cnt >=k);
            for(int j = k; j<=60; j++){
                if(mp.count(j-cnt))
                count += mp[j-cnt];
            }
            mp[cnt]++;
        }
        return 2*1ll*count + c;
    }
};