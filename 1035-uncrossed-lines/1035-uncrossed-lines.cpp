class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, vector <int> &nums1, vector <int> &nums2){
        if(i <=0 || j <= 0) return 0;
        int n = nums1.size();
        int m = nums2.size();
        if(dp[i][j]!=-1) return dp[i][j];
        int count  = 0;
        // try to match first array with something on second
        if(nums1[i-1]==nums2[j-1]){
            count = 1 + solve(i-1,j-1,nums1,nums2);
        }
        else count = max(solve(i-1,j,nums1,nums2),solve(i,j-1,nums1,nums2));
        return dp[i][j] = count;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        memset(dp,-1,sizeof dp);
        return solve(n,m,nums1,nums2);
    }
};