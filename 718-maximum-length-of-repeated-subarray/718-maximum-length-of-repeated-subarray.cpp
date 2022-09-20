class Solution {
    int dp[1001][1001];
public:
    int ans =0;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        find_maxi(nums1,nums2,0,0);
        return ans;
    }
    int find_maxi(vector <int> &num1,vector<int> &num2,int idx1, int idx2){
        if(idx1 == num1.size() || idx2 == num2.size()) return 0;
        int take = 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(num1[idx1]==num2[idx2]){
            take =  1 + find_maxi(num1,num2,idx1+1,idx2+1);
            ans = max(take,ans);
        }
        find_maxi(num1,num2,idx1+1,idx2);
        find_maxi(num1,num2,idx1,idx2+1);
        return dp[idx1][idx2] = take;
    }
};