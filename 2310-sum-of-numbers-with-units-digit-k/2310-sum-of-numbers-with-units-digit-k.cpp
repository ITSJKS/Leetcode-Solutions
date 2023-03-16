class Solution {
public:
    int minimumNumbers(int num, int k) {
        vector <int> last_k;
        int c = k;
        while(c <= num){
            last_k.push_back(c);
            c+=10;
        }
        vector <int> dp(num+10,10000);
        for(auto x:last_k){
            dp[x] = 1;
        }
        dp[0] = 0;
        for(int i = 1; i <=num; i++){
            if(dp[i] != 10000){
                for(auto x:last_k){
                    if(i + x <= num){
                        dp[i+x] = min(1 + dp[i],dp[i+x]);
                    }
                }
            }
        }
        if(dp[num] == 10000) return -1;
        return dp[num];
    }
};