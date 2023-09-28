class Solution {
public:
    int dp[4001];
    vector <int> kmp(string &s){
        int n = s.size();
        vector <int> lps(n,0);
        int len = 0 , i = 1;
        while(i < n){
            if(s[i] == s[len]){
                lps[i] = ++len;
                i++;
            }
            else{
                if(len == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
        return lps;
    }
    int deleteString(string s) {
        memset(dp,-1,sizeof dp);
       return solve(s,0) + 1;
    }
    int solve(string &s, int i){
        int n = s.size();
        if(i == n) return 0;
        if(dp[i]!=-1) return dp[i];
        string t;
        for(int j  = i; j <n; j++){
            t.push_back(s[j]);
        }
        vector <int> lps = kmp(t);
        int ans = 0;
        for(int j = 0; j <lps.size(); j++){
            if(2*lps[j] == (j+1)){
                ans = max(ans,1 + solve(s,i+lps[j]));
            }
        }
        return dp[i] = ans;
    }
};

/*
Entire string s ->

delete the first i letters of s if the first i letters of s are equal to the following i letters in s
for any i in the range 1 <= i <= s.length/2




*/