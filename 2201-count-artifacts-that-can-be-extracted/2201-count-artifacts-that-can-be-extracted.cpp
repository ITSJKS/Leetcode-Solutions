class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector <vector <int>> grid(n,vector <int>(n,0));
        for(auto x:dig){
            grid[x[0]][x[1]] = 1;
        }
        int count = 0;
        for(auto x:artifacts){
            int l1 = x[0] , r1 = x[1] , l2 = x[2] ,r2 = x[3];
            bool check = true;
            for(int i = l1; i <=l2; i++){
                for(int j = r1; j <=r2; j++){
                    check = check &grid[i][j];
                }
            }
            if(check) count++;
        }
        return count;
    }
};