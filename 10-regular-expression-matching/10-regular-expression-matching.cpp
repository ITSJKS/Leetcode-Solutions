class Solution {
    int dp[23][33];
public:
    bool isMatch(string s, string p) {
        if(p.length() == 0) return s.length() == 0;
        memset(dp,-1,sizeof(dp));
        return match(s,p,0,0);
    }
    bool match(string &s, string &p, int si, int pi){
        if(pi == p.length()){
            return si == s.length();
        }
        if(dp[si][pi]!=-1) return dp[si][pi];
        bool ismatch = si<s.length()?s[si] == p[pi]|| p[pi] == '.':false;
        bool star = pi+1<p.length()?p[pi+1] == '*':false;
        if(star){
            return dp[si][pi] =  (match(s,p,si,pi+2) || ismatch && match(s,p,si+1,pi));
        }
        return  dp[si][pi] = ismatch && match(s,p,si+1,pi+1);
    }
};