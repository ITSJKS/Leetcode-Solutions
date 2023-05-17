class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int k = numsDivide[0];
        int m = numsDivide.size();
        for(int i =1; i <m; i++){
            k = gcd(k,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i = 0; i <nums.size(); i++){
            if(k%nums[i] == 0) return i;
        }
        return -1;
        
    }
};