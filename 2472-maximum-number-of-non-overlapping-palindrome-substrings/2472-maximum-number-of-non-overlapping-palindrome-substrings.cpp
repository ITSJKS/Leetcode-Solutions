class Solution {
public:
    int memo[2001][2001];
    bool check(string &s, int i, int j){
        if(i > j) return true;
        if(memo[i][j]!=-1) return memo[i][j];
        if(s[i]!=s[j])   return  memo[i][j]  = false;
        return memo[i][j] = check(s,i+1,j-1);
    }
    int dp[2001];
    int solve(int ind, string &s, int k){
        if(ind >= s.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans = 0;
        ans = max(ans,solve(ind+1,s,k));
        for(int j = k; ind+j <=s.size(); j++){
            if(check(s,ind,ind+j-1)) ans = max(ans,1 + solve(ind+j,s,k));
        }
        return dp[ind] = ans;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        memset(memo,-1,sizeof(memo));
        memset(dp,-1,sizeof dp);
        check(s,0,n-1);
        return solve(0,s,k);
    }
};


/*
we are given a string s and a postive integer k
we need to select a non overlapping substring from the string s such that length of each substring is at least k and each substring is a palindrome
so at position we can do one thing we can either select the k length substring if it is a palindrome or we can ignore and move to next postion

*/