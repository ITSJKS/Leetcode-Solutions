class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector <int> v(nums.size());
        for(auto x:nums){
            v[x-1]++;
        }
        int i = 1;
        int a = 0,b = 0;
        for(auto x:v){
            if(x == 0) a = i;
            else if(x  == 2) b = i;
            i++;
        }
        return {b,a};
    }
};