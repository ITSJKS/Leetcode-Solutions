class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map <vector <int>,int> mp;
        for(auto x:grid){
            mp[x]++;
        }
        int n = grid.size();
        int ans = 0;
        for(int i = 0; i <n; i++){
            vector <int> col;
            for(int j = 0; j <n; j++){
                col.push_back(grid[j][i]);
            }
            if(mp.count(col)){
                ans += mp[col];
            }
        }
        return ans;
    }
};