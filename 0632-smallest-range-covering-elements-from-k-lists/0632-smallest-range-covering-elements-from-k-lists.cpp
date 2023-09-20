class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector <pair<int,int>> ordered;
        for(int i = 0; i <n; i++){
            for(auto &x:nums[i]) ordered.push_back({x,i});
        }
        sort(ordered.begin(),ordered.end());
        int i = 0, k = 0;
        vector<int> ans;
        unordered_map<int, int> count;
        for (int j = 0; j < ordered.size(); ++j) {
            if (! count[ordered[j].second]++) ++k;
            if (k == nums.size()) { 
                while (count[ordered[i].second] > 1) --count[ordered[i++].second]; 
                if (ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first) {
                    ans = vector<int>{ordered[i].first, ordered[j].first};
                }
            }
        }

        return ans;
    }
};

/*

we are given k list of sorted integers in non decreasing order 
find smallest range that includes at least one number from each of the k lists

3500 numbers 
each list is of size 50

4 10 15 24 26
0 0 12 20
5 18 22 30
*/