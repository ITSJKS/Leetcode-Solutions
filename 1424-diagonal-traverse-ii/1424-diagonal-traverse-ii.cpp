class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        vector <pair<pair<int,int>,int>> ans;
        for(int i = 0; i <n; i++){
            for(int j = 0; j <(nums[i].size()); j++){
                int sum = i + j;
                int val = nums[i][j];
                ans.push_back({{sum,j},val});
            }
        }
        sort(ans.begin(),ans.end());
        vector <int> res;
        for(auto &x:ans) res.push_back(x.second);
        return res;
        
    }
};