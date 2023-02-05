class Solution {
public:
    int dp[40000];
    int solve(int ind, int mask , vector<int>& nums1, vector<int>& nums2){
        if(ind >= nums2.size()) return 0;
        if(dp[mask]!=-1) return dp[mask];
        int ans = INT_MAX;
        int n = nums1.size();
        for(int i = 0; i <n; i++){
            if((mask&(1<<i))) continue;
            ans = min(ans,(nums1[ind]^nums2[i]) + solve(ind+1, mask | (1<<i) , nums1,nums2));
        }
        return dp[mask] = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,nums1,nums2);
    }
};