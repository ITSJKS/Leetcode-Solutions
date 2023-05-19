class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int dp[201][201];
    int solve(int i, int j, vector <vector <int>> &matrix){
        if(dp[i][j] !=-1) return dp[i][j];
        int maxi = 1;
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >=0 && ni < matrix.size() && nj >=0 && nj < matrix[0].size() && matrix[ni][nj] > matrix[i][j]){
                maxi = max(maxi,1 + solve(ni,nj,matrix));
            }
        }
            return dp[i][j] = maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans=  1;
        memset(dp,-1,sizeof dp);
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                ans = max(ans,solve(i,j,matrix));
            }
        }
        return ans;
    }
};

// {i,j} 