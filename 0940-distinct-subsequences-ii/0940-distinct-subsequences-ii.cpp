class Solution {
public:
    int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int dp[26][26] = {};
        int n = s.size();
        for(int k = 0; k <n;k++){
            int cur = s[k] - 'a';
            dp[cur][cur] += 1;
            for(int i = 0; i <26; i++){
                for(int j = 0; j <26; j++){
                    if(j == cur) continue;
                    dp[i][cur] = (dp[i][cur] + dp[i][j])%mod;
                }
            }
        }
        int sum = 0;
        for(int i = 0; i <26; i++){
            for(int j = 0; j <26; j++) sum =(sum +  dp[i][j])%mod;
        }
        return sum;
    }
};
/*
we need to form distinct non-empty subsequences 

we can do something like this
we can find keep a 26*26 vector 
where we will contain value like number of subsequnce starting with ch1 and ending with ch2
then we can add our current 
26*26

*/