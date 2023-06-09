class Solution {
public:
    bool solve(int mask, int k, int sum, int req, vector <int> &nums, int n,vector <int> &dp){
        if(k == 0){
            if(mask == (1<<n) - 1) return true;
            return false;
        }
        if(sum == req){
            return solve(mask,k-1,0,req,nums,n,dp);
        }
        if(dp[mask]!=-1) return dp[mask];
        bool check = false;
        for(int i = 0; i <n; i++){
            if(mask&(1<<i)) continue;
            if(sum + nums[i] <= req){
                mask |= 1<<i;
                check |= solve(mask,k,sum+nums[i],req,nums,n,dp);
                mask ^= 1<<i;
            }
        }
        return dp[mask] = check;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k) return false;
        int req = sum/k;
        vector <int> dp(1<<n,-1);
        return solve(0,k,0,req,nums,n,dp);
    }
};
// we can create a bitmask for each k subset 
// like for our first subset if we are selecting 1st 3rd and 5th index , we can mark them as 