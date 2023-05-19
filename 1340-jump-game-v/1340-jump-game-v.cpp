class Solution {
public:
    int dp[1001] = {};
    int solve(int idx, vector <int> &arr, int d){
        int n = arr.size();
        int maxi = 1;
        if(dp[idx]) return dp[idx];
        for(int j = idx+1; j <= min(n-1,idx+d) && arr[j] <arr[idx]; j++){
            maxi = max(maxi,1 + solve(j,arr,d));
        }
        for(int i = idx-1; i>=max(0,idx-d) && arr[i] <arr[idx]; i--){
            maxi = max(maxi,1 + solve(i,arr,d));
        }
        return dp[idx] = maxi;
    }
    int maxJumps(vector<int>& arr, int d) {
        int maxi = 1;
        for(int i = 0; i <arr.size(); i++){
            maxi = max(maxi,solve(i,arr,d));
        }
        return maxi;
    }
};