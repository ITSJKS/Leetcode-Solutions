class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector <vector <int>> dp(n+1,vector <int> (3,-1));
        return solve(nums,0,0,dp);
    }
    int solve(vector <int> &nums, int i, int k,vector <vector <int>> &dp){
        if(i == nums.size()){
            if(k == 0) return 0;
            return -1000000;
        } 
        if(dp[i][k]!=-1) return dp[i][k];
        int take_it = nums[i] + solve(nums,i+1,(k+nums[i])%3,dp);
        int dont_take = solve(nums,i+1,k,dp);
        return dp[i][k] = max(take_it,dont_take);
    }
};