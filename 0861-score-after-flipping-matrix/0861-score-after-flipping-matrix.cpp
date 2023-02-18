class Solution {
public:
    void convert_no(vector <int>&g){
        int n = g.size();
        for(int i = 0; i <n; i++){
            g[i] = 1 - g[i];
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long ans = 0;
        for(int j = 0; j <m; j++){
            int cnt = 0;
            for(int i = 0; i <n; i++){
                if(j == 0 && grid[i][j] == 0){
                    convert_no(grid[i]);
                }
               cnt += grid[i][j]==1; 
        }
            ans += max(cnt,n-cnt)*(1<<(m-j-1));
        }
        return ans;
        
    }
};