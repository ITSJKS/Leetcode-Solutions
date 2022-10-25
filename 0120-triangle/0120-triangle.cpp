class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return ms(triangle,triangle.size());
    }
    int f(int i, int j, vector<vector<int>>& triangle,vector<vector<int>>& dp){
    if(i == triangle.size() -1) return triangle[i][j];
    if(i >= triangle.size() || j >= triangle[i].size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int down = 0,d_right = 0;
    down = f(i+1,j,triangle,dp);
    d_right = f(i+1,j+1,triangle,dp);
    return dp[i][j] = min(down,d_right) + triangle[i][j];
}
int ms(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n,vector <int>(n,-1));
	return f(0,0,triangle,dp);
}
};