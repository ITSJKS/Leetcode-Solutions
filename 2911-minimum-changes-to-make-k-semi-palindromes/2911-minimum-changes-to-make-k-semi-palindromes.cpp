class Solution {
public:
    int minMoves(string &s, int st, int k){
            int len  = k - st + 1;
            // if(len <= 2) return 1e9;
            int moves = 1e9;
            for(int i = 2; i*i <=len; i++){
                if(len%i == 0){
                    string t;
                    for(int j = st; j<=k; j+=i) t.push_back(s[j]);
                    int l = 0, r = t.size() - 1;
                    int cnt = 0;
                    while(l < r){
                        if(s[l] != s[r]) cnt++;
                        l++,r--;
                    }
                    moves = min(moves,cnt);
                }
            }
        return moves;
    }
    vector<vector<int>> fact;
    int n;
    string s;
    int dp2[201][201];
    int ChangesForSemiPalindrome (int l, int r) {
        int n = r - l + 1;
        int ans = 1e9;
        if(dp2[l][r]!=-1) return dp2[l][r];
        for (auto f : fact[n]) {
            int len = n/f;
            int change = 0;
            
            for (int part = 0; part < f; part ++) { 
                for (int i = 0; i < len/2; i ++) 
                    if (s[l+i*f+part] != s[l+(len-i-1)*f+part]) change ++;
            }
            ans = min (ans, change);
        }
        return dp2[l][r] = ans;
    }
    int dp[201][201];
    int solve(int st, int cur, string &s){
        if(st == n){
            return (cur == 0) ? 0:1e9;
        }
        if(cur == 0) return 1e9;
        if(dp[st][cur]!=-1) return dp[st][cur];
        int ans = 1e9;
        for(int k = st; k<n; k++){
            int count = ChangesForSemiPalindrome(st,k) + solve(k+1,cur-1,s);
            ans = min(ans,count);
        }
        return dp[st][cur] = ans;
        
    }
    int minimumChanges(string s_, int k) {
        s = s_;
        n = s.size();
        memset(dp,-1,sizeof dp);
        memset(dp2,-1,sizeof dp);
        fact.clear(), fact.resize(n+1);
        for (int j = 1; j <= n; j ++) {
            for (int i = j+j; i <= n; i += j) fact[i].push_back(j);
        }
        return solve(0,k,s);
    }
};

/*
abcdef
we will start from string abcdef
then we can try to partition it as (a)


*/