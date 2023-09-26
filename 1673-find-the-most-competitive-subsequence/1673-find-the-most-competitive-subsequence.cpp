class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans;
        for(int i = 0; i <n; i++){
            int rem = n- i;
            while(ans.size() && ans.back() > nums[i] && ans.size() + rem > k){
                ans.pop_back();
            }
            if(ans.size() < k)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
/*
basically we are asked to find lexicographically smallest sequnce containing k numbers
*/