class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int x = m - 1 , y = 0;
        while(x >= 0 && y < n){
            if(matrix[y][x] == target) return true;
            else if(matrix[y][x]<target) y++;
            else x--;
        }
        return false;
    }
};