class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int rem = 0;
        mp[0] = 1;
        int sum = 0,count = 0;
        for(auto x:nums){
            sum += x;
            rem = sum%k;
            if(rem<0) rem+=k;
            count += mp[rem];
            // cout<<mp[rem]<<" "<<count<<endl;
            mp[rem]++;
        }
        return count;
    }
};