class Solution {
    int dp[201][201];
public:
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return is_true(s1,s2,s3,0,0,0);
    }
    bool is_true(string &s1,string &s2, string &s3, int i, int j, int k){
        if(k == s3.length()){
            if(i == s1.length() && j == s2.length()) return true;
            else return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i] == s3[k]){
            if(s1[i] == s2[j]){
                return dp[i][j] = is_true(s1,s2,s3,i+1,j,k+1) || is_true(s1,s2,s3,i,j+1,k+1);
            }
            else{
               return dp[i][j] =is_true(s1,s2,s3,i+1,j,k+1); 
            }
        }
        else if(s2[j] == s3[k]){
            return dp[i][j] = is_true(s1,s2,s3,i,j+1,k+1);
        }
        else{
            return dp[i][j] = 0;
        }
        return true;
    }
};