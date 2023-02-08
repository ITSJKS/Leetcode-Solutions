class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector <vector <int>> prefix(n+1,vector <int>(m+1,0));
        for(int i =1; i <=n; i++){
            for(int j = 1; j <=m; j++){
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1]-prefix[i-1][j-1]+mat[i-1][j-1];
            }
        }
        for(int i = 1; i <=n; i++){
                int r_max = min(n,i+k);
                 int r_min = max(1,i-k);
            for(int j = 1; j <=m; j++){
                int value = 0;
                 int c_max = min(m,j+k);
                 int c_min = max(1,j-k);
                 value += prefix[r_max][c_max];
                 value -= prefix[r_min-1][c_max];
                 value -= prefix[r_max][c_min-1];
                 value += prefix[r_min-1][c_min-1];
                 mat[i-1][j-1] = value;
            }
        }
        return mat;
    }
};