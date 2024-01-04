class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;
        for(auto &x:nums){
            if(x&1) continue;
            else count++;
        }
        return count>=2;
    }
};