long long dp[1001][10001];
bool check = true;
int mod =  1e9 + 7;
void precompute(){
    dp[1][1] = 1;
    long long sum = 1;
    for(int i =2; i<=1000; i++){
        dp[i][1] = sum;
        for(int j = 2; j<=i-1; j++){
            dp[i][j] = (dp[i-1][j-1] + (i-1)*1ll*dp[i-1][j]%mod)%mod;
            sum = (sum + dp[i][j])%mod;
        }
        dp[i][i] = 1;
        sum = (sum+1)%mod;
    }
    check = false;
}
class Solution {
public:
    int rearrangeSticks(int n, int k){
        if(check) precompute();
        return dp[n][k];
    }
};