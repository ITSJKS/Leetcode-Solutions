class Solution {
public:
    // 3 6 9 12
    // for any index i, index j = i+1 to n, we check if dp[i][diff] is 0 or not, if zero we keep dp[j][diff] as two length , else dp[j][diff] =  1 + dp[i][diff]
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector <vector <int>> dp(n+1,vector <int>(1001,0));
        int maxi = 0;
        for(int i = 0; i <n; i++){
            for(int j = i+1; j <n; j++){
                int diff = nums[j] - nums[i];
                if(dp[i][diff+500] == 0){
                    dp[j][diff+500] = 2;
                }
                else{
                    dp[j][diff+500] = 1 + dp[i][diff+500];
                }
                maxi = max(maxi,dp[j][diff+500]);
            }
        }
        return maxi;
        
    }
};