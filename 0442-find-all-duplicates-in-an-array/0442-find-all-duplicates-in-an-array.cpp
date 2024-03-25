class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        int n = nums.size();
        for(int i = 0;  i < n; i++){
            int curr = abs(nums[i]) - 1;
            if(nums[curr]<0) ans.push_back(abs(nums[i]));
            nums[curr]*=-1;
        }
        return ans;
    }
};