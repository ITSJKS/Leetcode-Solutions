class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size() == 1&& nums[0] == 0) return 0; 
        int maxi_2 = 0;
        int count = 0;
        for(auto x:nums){
            if(x == 0) continue;
            int msb = 32 - __builtin_clz(x);
            maxi_2 = max(maxi_2,msb);
            count += __builtin_popcount(x);
        }
        return maxi_2 + count - 1;
    }
};
/*
we can find the maximum power of 2 in nums , then we can 
5 is 101 -> we will always need 2 1 which can come only from 2 double increment and 2 add increment
0 -> 1-> 2->4 ->5
for 15 1111 -> we will need 4 increment
0->1->2->3->6->7->14->15
*/
