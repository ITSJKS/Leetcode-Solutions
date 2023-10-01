class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end())+1;
        vector <int> factors(maxi,0);
        for(int i = 0; i <n; i++){
            for(int j = 1; j*j <= nums[i]; ++j){
                if(nums[i]%j == 0){
                    int first = j;
                    int second = nums[i]/j;
                    factors[first] = gcd(factors[first],nums[i]);
                    factors[second] = gcd(factors[second],nums[i]);
                }
            }
        }
        int count = 0;
        for(int i =1; i <maxi; i++){
            if(factors[i] == i) count++;
        }
        return count;
    }
};