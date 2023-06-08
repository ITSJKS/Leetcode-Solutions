class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = 0, j = m-1;
        int count = 0;
        while(i <n && j >=0){
            int num = grid[i][j];
            if(num  < 0){
                count += n - i;
                j--;
            }
            else{
                i++;
            }
        }
        return count;
    }
};
// 2nd way 
// row is non increasing therefore the 