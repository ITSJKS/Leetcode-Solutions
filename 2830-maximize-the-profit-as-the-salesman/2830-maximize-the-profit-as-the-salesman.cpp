class Solution {
public:
    static const int N = 1e5 + 1;
    int dp[N];
    int solve(int ind, vector <vector <int>> &offers, vector <int> &second){
        if(ind >= offers.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        auto last = offers[ind][1];
        auto it = lower_bound(second.begin(),second.end(),last+1) - second.begin();
        return dp[ind] = max(solve(it,offers,second) + offers[ind][2] , solve(ind+1,offers,second));
        
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        memset(dp,-1,sizeof dp);
        vector <int> second;
        for(auto &x:offers){
            second.push_back(x[0]);
        }
        return solve(0,offers,second);
    }
};