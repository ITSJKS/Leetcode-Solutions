class Solution {
public:
    int mod = 1e9 + 7;
    int dp[10001][5][10][10];
    int solve(int ind, int cur, int pos1,int pos2 , string &s){
        if(cur == 5){
            if(pos1 == 0 && pos2 == 0) return 1;
            else return 0;
        }
        if(ind == s.size()){
            return 0;
        }
        if(dp[ind][cur][pos1][pos2]!=-1) return dp[ind][cur][pos1][pos2];
        int pos = cur;
        long long count = 0;
        if(pos == 0){
            count = (count + solve(ind+1,cur+1,pos1^(s[ind]-'0'),pos2,s))%mod;
        }
        else if(pos == 1){
            count = (count + solve(ind+1,cur+1,pos1,pos2^(s[ind]-'0'),s))%mod;
        }
        else if(pos == 2){
            count = (count + solve(ind+1,cur+1,pos1,pos2,s))%mod;
        }
        else if(pos == 4 && pos1==(s[ind]-'0')){
            count = (count + solve(ind+1,cur+1,pos1^(s[ind]-'0'),pos2,s))%mod;
        }
        else if(pos == 3 && pos2 ==(s[ind]-'0')){
            count = (count + solve(ind+1,cur+1,pos1,pos2^(s[ind]-'0'),s))%mod;
        } 
        count = (count + solve(ind+1,cur,pos1,pos2,s))%mod;
        return dp[ind][cur][pos1][pos2] = count;
    }
    int countPalindromes(string s) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,0,0,s);
    }
};

// 99999
// subsequence of length 5
// so we basically need subsequence of length 2 , and put anything at third