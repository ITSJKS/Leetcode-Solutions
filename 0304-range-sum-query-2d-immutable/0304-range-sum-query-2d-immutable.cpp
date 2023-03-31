class NumMatrix {
public:
    vector <vector <int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix = vector <vector <int>> (n+1,vector <int>(m+1,0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int val1 = prefix[row2+1][col2+1];
        int val2 = prefix[row2+1][col1];
        int val3 = prefix[row1][col2+1];
        int val4 = prefix[row1][col1];
        return val1 - val2 - val3 + val4;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */