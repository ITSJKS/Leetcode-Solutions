class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int mod = 1e9 + 7;
        int dp[3] = {0};
        for(auto &x:nums){
            if(x == 0) dp[x] = ((dp[x] + dp[x])%mod +  1)%mod;
            else dp[x] = ((dp[x] + dp[x])%mod +  dp[x-1])%mod;
        }
        return dp[2];
    }
};
// x == 0
// all previous of 0
// x == 1
// all previous sequence of 0 1 -> prev 1 and prev 0 both as now it will extend or form subsequence with both 
// x == 2

// all previous sequnce of 1 and 2 both as it will form sequence with 1 as well as 2
// 0...0 1..1.. 2... cur 2