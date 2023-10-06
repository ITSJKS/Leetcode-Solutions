class Solution {
public:
    int integerBreak(int n) {
        vector <int> dp(58,0);

        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <=n; i++){
            int maxi = 1;
            for(int j = 1; j <i; j++){
                if(i-j>0){
                    int temp  = max(j*dp[i-j],j*(i-j));
                    maxi = max(maxi,temp);
                }
                dp[i] = maxi;
            }
        }
        return dp[n];
    }
};