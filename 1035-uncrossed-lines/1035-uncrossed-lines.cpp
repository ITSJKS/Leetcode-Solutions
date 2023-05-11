class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, vector <int> &nums1, vector <int> &nums2){
        if(i <0 || j < 0) return 0;
        int n = nums1.size();
        int m = nums2.size();
        if(dp[i][j]!=-1) return dp[i][j];
        int count1 = solve(i-1,j,nums1,nums2);
        int count2 = solve(i,j-1,nums1,nums2);
        // try to match first array with something on second
        for(int k = j; k>=0; k--){
            if(nums1[i] == nums2[k]){
                count1 = max(1 + solve(i-1,k-1,nums1,nums2),count1);
            }
        }
        for(int k = i; k>=0; k--){
            if(nums1[k] == nums2[j]){
                count2 = max(1 + solve(k-1,j-1,nums1,nums2),count2);
            }
        }
        return dp[i][j] = max(count1,count2);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        memset(dp,-1,sizeof dp);
        return solve(n-1,m-1,nums1,nums2);
    }
};