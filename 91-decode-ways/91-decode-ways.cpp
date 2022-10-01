class Solution {
    int dp[101];
public:
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return find_ways(0,s,s.length());
    }
    int find_ways(int i, string s, int n){
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return 0;
        int ans = 0;
        //Take the number 
        ans += find_ways(i+1,s,n);
        // dont take the digit
        if(i<n-1 && (s[i]=='1' || (s[i] == '2' && s[i+1]<'7'))) ans += find_ways(i+2,s,n);
        return dp[i] = ans;
    }
};