class Solution {
public:
    int dp[501][501][2];
    int solve(int i, int  j ,bool flag, vector <int> &nums1, vector <int>&nums2){
        int n = nums1.size();
        int m = nums2.size();
        if(i >= n || j >= m){
            if(flag) return 0;
            return -1e9;
        }
        if(dp[i][j][flag]!=-1) return dp[i][j][flag];
        // take the current element from first index and we can choose second one to be from j to n=1
        int ans = -1e9;
        ans = max(ans,nums1[i]*nums2[j] + solve(i+1,j+1,true,nums1,nums2));
        ans = max(ans, solve(i+1,j,flag,nums1,nums2));
        ans = max(ans, solve(i,j+1,flag,nums1,nums2));
        return dp[i][j][flag] = ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,false,nums1,nums2);
    }
};

/*
I need to find maximum dot product between non empty subsequence of nums1 and nums2
we can try to find maximum values from length l
then we can try to 
*/