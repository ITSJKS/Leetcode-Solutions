class Solution {
public:
    int count(int i, int j, string &s){
        int cnt = 0;
        while(i < j){
            if(s[i]!=s[j]) cnt++;
            i++;
            j--;
        }
        // cout<<i <<" "<<j<<" "<<cnt<<endl;
        return cnt;
    }
    int dp[101][101];
    int solve(int i,int cur,string &s, int k){
        if(i == s.size()){
            if(cur == k) return 0;
            return 1e9;
        }
        if(dp[i][cur]!=-1) return dp[i][cur];
        int ans = 1e9;
        for(int j = i; j <s.size(); j++){
            ans = min(ans,count(i,j,s) + solve(j+1,cur+1,s,k));
        }
        return dp[i][cur] = ans;
        
    }
    int palindromePartition(string s, int k) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,s,k);
    }
};

/*
we are given a string s containing lowercase letters and an integer k
we need to first change some character of s to lowercase english letters
we need to divide s into k non-empty disjoint substring such that each substring is a palindrome

a substring of length cur will be a palindrome if s[i - len] == s[i] 

*/