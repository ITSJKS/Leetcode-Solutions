class Solution {
public:
   bool f(int i, int j, string &s, string &t,vector <vector <int>> &dp){
        if( i == 0 && j == 0) return true;
        if(i == 0 && j > 0) return false;
        if(j == 0 && i > 0) {
            for(int k = 1; k <=i; k++){
                if(s[k-1] != '*') return false;
            }
            return true;
        } 
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i-1] == t[j-1] || s[i-1] == '?') 
            return dp[i][j]= f(i-1,j-1,s,t,dp);
        
        if(s[i-1] == '*'){
            return dp[i][j] = f(i-1,j,s,t,dp) | f(i,j-1,s,t,dp);
        }
        return dp[i][j] = false;
    }
bool isMatch(string s, string t)
{
        swap(s,t);
        int n = s.size(),m = t.size();
        vector <vector <int>> dp(n+1,vector <int>(m+1,-1));
        return f(n,m,s,t,dp);
}
    
};