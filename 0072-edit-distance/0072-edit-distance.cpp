class Solution {
public:
    int f(int i, int j, string &s, string &t,vector <vector <int>>&dp){
        // BC
        if(i == 0) return j;
        if(j == 0) return i;
        // match 
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1] == t[j-1]){
            return dp[i][j] = f(i-1,j-1,s,t,dp);
        }
        else{
            return dp[i][j] = min(1 + f(i,j-1,s,t,dp),min(1+ f(i-1,j,s,t,dp),1 + f(i-1,j-1,s,t,dp)));
        }
        return 0;
        // notMatch
    }
    int minDistance(string s, string t) {
        int n = s.size() , m = t.size();
        // vector <vector <int>> dp(n+1,vector <int>(m+1,0));
        vector <int> prev(m+1),cur(m+1);
        for(int i = 0; i <=m; i++){
            prev[i] = i;
        }
        for(int i = 1; i <=n; i++){
            cur[0] = i;
            for(int j = 1; j <=m; j++){
                if(s[i-1] == t[j-1]){
                    cur[j] = prev[j-1];
        }
                 else{
                        cur[j] = min(1 + cur[j-1],min(1+ prev[j],1 + prev[j-1]));
        }
            }
            prev = cur;
        }
        return prev[m];
        
        // return f(n,m,s,t,dp);
    }
};