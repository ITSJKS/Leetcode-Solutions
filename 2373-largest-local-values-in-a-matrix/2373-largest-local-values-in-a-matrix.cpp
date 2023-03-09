class Solution {
public:
    int largest(vector <vector <int>> &grid,int i, int j){
        int maxi = 0;
        for(int k = i; k <i+3; k++){
            for(int l = j; l<j+3; l++){
                maxi = max(maxi,grid[k][l]);
            }
        }
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector <vector <int>> ans(n-2,vector <int>(n-2));
        for(int i = 0; i <n-2; i++){
            for(int j = 0; j <n-2; j++){
                ans[i][j] = largest(grid,i,j);
            }
        }
        return ans;
    }
};