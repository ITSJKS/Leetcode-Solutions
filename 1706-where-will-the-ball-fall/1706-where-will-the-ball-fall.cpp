class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector <int> ans(grid[0].size());
        for(int i = 0; i <m; i++){
            ans[i] = find_ans(0,i,grid);
        }
        
    return ans;
    }
    int find_ans(int r, int c, vector <vector <int>> &grid){
        if(r == grid.size()) return c;
        int next_col = c + grid[r][c];
        if(next_col < 0 || next_col >= grid[0].size() || grid[r][c] != grid[r][next_col]){
            return -1;
        }
        return find_ans(r+1,next_col,grid);
    }
};
