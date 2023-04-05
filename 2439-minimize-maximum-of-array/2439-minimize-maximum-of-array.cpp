class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        vector <long long> prefix(nums.size());
        int n = nums.size();
        prefix[0] = nums[0];
        for(int i = 1; i <n; i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
        for(int i = 0; i <n; i++){
            prefix[i] = ceil(prefix[i]/(double)(i+1));
        }
        return *max_element(prefix.begin(),prefix.end());
    }
};