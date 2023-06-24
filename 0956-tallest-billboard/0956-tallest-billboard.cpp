class Solution {
public:
    int dp[21][10001];
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        memset(dp,-1,sizeof dp);
        return solve(0,0,rods);
    }
    int solve(int ind , int diff, vector <int> &rods){
        if(ind == rods.size()){
            if(diff == 0) return 0;
            return -5000;
        }
        if(dp[ind][5000+diff]!=-1) return dp[ind][diff+5000];
        int not_take = solve(ind+1,diff,rods);
        int take_with_first = rods[ind] + solve(ind+1,diff+rods[ind],rods);
        int take_with_second = solve(ind+1,diff-rods[ind],rods);
        return dp[ind][diff+5000] = max({not_take,take_with_first,take_with_second});
    }
};