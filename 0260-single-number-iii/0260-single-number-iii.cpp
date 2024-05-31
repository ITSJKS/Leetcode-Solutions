class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x_or = 0;
        for(auto x:nums) x_or ^= x;
        int ans = x_or;
        x_or = __builtin_ctz(x_or);
        int n = nums.size();
        int ans1 = 0;
        for(auto x:nums){
            if((x>>x_or)&1) ans1^=x;
        }
        return {ans1,ans1^ans};
    }
};