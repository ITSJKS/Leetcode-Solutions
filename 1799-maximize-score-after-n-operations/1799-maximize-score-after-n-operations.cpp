class Solution {
public:
    int dp[8][17000];
    int solve(int idx, int mask, vector <int> &nums){
        int n = nums.size();
        if(idx == n/2) return 0;
        // try all pair with current elem
        if(dp[idx][mask]!=-1) return dp[idx][mask];
        int cur_sum = 0;
        for(int i = 0; i <n; i++){
            if((mask&(1<<i)) == 0){
                for(int j = i+1; j<n; j++){
                    if((mask&(1<<j)) == 0){
                         int new_mask = mask | (1<<i);
                            new_mask |= 1<<j;
                        cur_sum = max(cur_sum, (idx+1)*gcd(nums[i],nums[j]) + solve(idx+1,new_mask,nums));
                    }
                }
            }
        }
        return dp[idx][mask] = cur_sum;
    }
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,nums);
    }
};