class Solution {
public:
    int mod =  1e9 + 7;
    int dp[101][101][101];
    int solve(int idx, int n, int p, int minProfit, vector <int> &group, vector <int> &profit){
       if(n < 0) return 0 ;
        if(idx == -1){
            if(p>=minProfit)
                return 1;
            return 0;
        }
        if(dp[idx][n][p] != -1) return dp[idx][n][p];
        // take it
        int c = 0;
        c = (c + solve(idx-1,n-group[idx],min(minProfit,p+profit[idx]),minProfit, group, profit))%mod;
        c = (c + solve(idx-1,n,p,minProfit,group,profit))%mod;
        return dp[idx][n][p] = c;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        int size = group.size();
        return solve(size-1,n,0,minProfit,group,profit);
        
    }
};

// start from last index
// if we take it , solve(idx - 1, n - group[idx] , p + profit[idx])
// else solve(idx-1,n,p);
// if(n < 0 ) return;
// if(p > minProfit) count++;