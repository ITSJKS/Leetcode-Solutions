class Solution {
public:
    int dp[11][2][2];
    int solve(string &s,int idx, bool flag,bool taken,vector <string> &digits){
        if(idx == s.size()) return 1&taken;
        if(dp[idx][flag][taken]!=-1) return dp[idx][flag][taken];
        int cnt = 0;
        char up = '9';
        if(flag) up = s[idx];
        for(auto x:digits){
            char y = x[0];
            if(y <= up){
                bool new_flag = flag && (y==up);
                cnt += solve(s,idx+1,new_flag,true,digits);
            }
        }
        if(!taken)
        cnt += solve(s,idx+1,false,taken,digits);
        return dp[idx][flag][taken] = cnt;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof dp);
        return solve(s,0,true,false,digits);
    }
};