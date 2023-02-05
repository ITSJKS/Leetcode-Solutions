class Solution {
public:
    int solve(int ind, int mask , int ns, vector <int> &nums,vector <int> &dp){
        if(ind <0) return 0;
        if(dp[mask]!=-1) return dp[mask];
        int bit = 1;
        for(int i = 1; i <=ns; i++){
            int rem = (mask/bit)%3;
            if(rem){
                dp[mask] = max(dp[mask],(nums[ind]&i) + solve(ind-1,mask-bit,ns,nums,dp));
            }
            bit*=3;
        }
        return dp[mask];
    }
    int maximumANDSum(vector<int>& nums, int ns) {
        int max_mask = pow(3,ns)-1;
        vector <int> dp(max_mask+1,-1);
        int n = nums.size();
        return solve(n-1,max_mask,ns,nums,dp);
    }
};