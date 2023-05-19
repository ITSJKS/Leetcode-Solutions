class Solution {
public:
    int mod = 1e9 + 7;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int dp[1001][1001];
    int solve(int i, int j, vector <vector <int>> &matrix){
        if(dp[i][j] !=-1) return dp[i][j];
        int count = 1;
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >=0 && ni < matrix.size() && nj >=0 && nj < matrix[0].size() && matrix[ni][nj] > matrix[i][j]){
                count = (count + solve(ni,nj,matrix))%mod;
            }
        }
            return dp[i][j] = count;
    }
    int countPaths(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count =  0;
        memset(dp,-1,sizeof dp);
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                count = (count + solve(i,j,matrix))%mod;
            }
        }
        return count;
    }
};

