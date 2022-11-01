class Solution {
public:
    int f(int i, int k , vector <int> &arr, vector <int> &dp){
        if(i == arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int len = 0, maxi = INT_MIN;
        int ans = INT_MIN;
        for(int idx = i; idx < min((int)arr.size(),i+k); idx++){
            len++;
            maxi = max(maxi,arr[idx]);
            ans = max(ans,len*maxi + f(idx+1,k,arr,dp));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
    vector <int> dp(n+1,-1);
        return f(0,k,arr,dp);
    }
};