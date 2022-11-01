class Solution {
public:
    int f(int i , int j, vector <int> &a,vector <vector <int>> &dp){
    if(i > j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int maxi= 0;
    for(int k = i; k<=j; k++){
       maxi  = max(maxi,a[i-1]*a[k]*a[j+1] + f(i,k-1,a,dp) + f(k+1,j,a,dp));
    }
    return dp[i][j] = maxi;
}
    int maxCoins(vector<int>& a) {
    int n = a.size();
    vector <vector <int>> dp(n+2,vector <int>(n+2,0));
    a.insert(a.begin(),1);
    a.push_back(1);
    for(int i = n; i >=1; i--){
        for(int j  =  1; j <=n; j++){
            if(i > j) continue;
int maxi= 0;
for(int k = i; k<=j; k++){
   maxi  = max(maxi,a[i-1]*a[k]*a[j+1] + dp[i][k-1] + dp[k+1][j]);
}
dp[i][j] = maxi;
        }
    }
	return dp[1][n];
    }
    
};