class Solution {
public:
    double solve(int ind, int target, vector <double> &prob,vector <vector <double>> &dp){
        if(ind == prob.size())
            return (target == 0) ? 1.0:0.0;
        if(target < 0) return 0;
        if(dp[ind][target]!=-1) return dp[ind][target];
        // it comes head
        double ans = 0;
        ans += prob[ind]*solve(ind+1,target-1,prob,dp);
        ans += (1.00 - prob[ind])*solve(ind+1,target,prob,dp);
        return dp[ind][target] = ans;
    }
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector <vector <double>> dp(n+1,vector <double>(target+1,-1));
        return solve(0,target,prob,dp);
    }
};