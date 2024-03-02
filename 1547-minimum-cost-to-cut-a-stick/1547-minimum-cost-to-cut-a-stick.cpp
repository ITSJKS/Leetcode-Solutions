class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector <vector <int>> dp(m,vector <int>(m,-1));
        function <int(int,int)> solve = [&](int start, int end){
            if(dp[start][end]!=-1) return dp[start][end];
            if(start > end) return 0;
            int ans =1e9;
            for(int ind = start; ind <=end; ind++){
                int cost = cuts[end+1]-cuts[start-1] + solve(start,ind-1) + solve(ind+1,end);
                ans = min(ans,cost);
            }
            return dp[start][end] = ans;
        };
        return solve(1,m-2);
    }
};
/*
N units we can cut the stick according to cuts
cost of one cut is length of the stick on which you are doing the cut



*/