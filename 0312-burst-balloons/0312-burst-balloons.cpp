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
    vector <vector <int>> dp(n+2,vector <int>(n+2,-1));
    a.insert(a.begin(),1);
    a.push_back(1);
	return f(1,n,a,dp);
    }
    
};