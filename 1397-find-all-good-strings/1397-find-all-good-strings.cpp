class Solution {
public:
    int mod = 1e9 + 7;
    vector <int> lps;
    int dp[501][2][51];
    int solve(int ind, bool flag, int cur, string &s, string &evil){
        int n = s.size();
        int size = evil.size();
        if(cur == evil.size()) return 0;
        if(ind == n) return 1;
        if(dp[ind][flag][cur]!=-1) return dp[ind][flag][cur];
        int ub = flag?s[ind]-'a':25;
        int count = 0;
        for(int i = 0; i <=ub; i++){
            bool new_flag = (i==ub)&flag;
            int j = cur;
            while(j && evil[j]!=(i+'a')) j = lps[j-1];
            if(evil[j] == (i+'a')) j++;
            count = (count + solve(ind+1,new_flag,j,s,evil))%mod;
        }
        return dp[ind][flag][cur] = count;
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        int m = evil.size();
        lps.resize(m,0);
        int len = 0, i = 1;
        while(i < m){
            if(evil[i] == evil[len]){
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
        memset(dp,-1,sizeof dp);
        int cnt1 = solve(0,true,0,s2,evil);
        memset(dp,-1,sizeof dp);
        int cnt2 = solve(0,true,0,s1,evil);
        if(s1.find(evil)==string::npos) cnt1 = (cnt1+1)%mod;
        return (cnt1-cnt2+mod)%mod;
    }
};

/*
given s1 and s2 of size n
and string evil
Good string has size n
s1 < str<s2
it doesnot contain evil string as a substring
we can apply digit dp here
we can find number of words which are smaller than equal to s2
we can find number of words which are smaller than equal to s1
we can check for s1 , answer will be cnt(s2) - cnt(s1) + check(s1);

*/