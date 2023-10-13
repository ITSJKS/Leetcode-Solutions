class Solution {
public:
    int k;
    int mod = 1e9 + 7;
    int dp[100001];
    int solve(int ind, string &s, int len){
        if(ind == s.size()) return 1;
        if(s[ind] == '0') return 0;
        if(dp[ind]!=-1) return dp[ind];
        int count = 0;
        for(int j = 1; j <=len; j++){
            if(ind +j  > s.size()) break;
            string t = s.substr(ind,j);
            if(stol(t) <= k) count = (count + solve(ind+j,s,len))%mod;
        }
        return dp[ind] = count;
    }
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof dp);
        this->k = k;
        int len = to_string(k).size();
        return solve(0,s,len);
    }
};