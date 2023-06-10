int sum_and(const vector<int>& r1, const std::vector<int>& r2) {
        int ans = 0;
        for (int i = 0; i < r1.size(); i++) {
            ans += r1[i] && r2[i];
        }
        return ans;
    }
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(std::vector<std::vector<int>>& grid) {
        int n = grid.size();    
        if(n == 1){
            if(accumulate(grid[0].begin(),grid[0].end(),0ll) == 0) return {0};
            return {};
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sum_and(grid[i], grid[j]) == 0) {
                    return vector <int>{i, j};
                }
            }
        }
        return vector <int>{};
    }
    

};