class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfWays(int n) {
        int mid = n/2 + 1;
        vector <int> dp(mid);
        dp[0] = 1;
        for(int i = 1; i <mid; i++){
            for(int j = 0; j < i; j++){
                dp[i] = (dp[i] + (long long)dp[j]*dp[i-j-1]%mod)%mod;
            }
        }
        return dp[n/2];
    }
};
// we can find the number of way for numsPeople by using dp
// we can divide the n people into two group 
// 1 2 3 4 5 6 7 8 -> if 1 and 4 are shaking hand , there should be even number of people between them and there should be even number of people betweeen 4 and 1 as those points can't shake hand with others outside those points