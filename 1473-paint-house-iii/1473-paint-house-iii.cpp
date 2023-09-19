class Solution {
public:
    int dp[101][22][101];
    int solve(int ind, int prev, int cur, vector <int>&houses, vector <vector <int>>&cost, int n, int target){
        if(cur>target) return 1e9;
        if(ind == houses.size()){
            if(cur == target) return 0;
            return 1e9;
        }
        if(dp[ind][prev][cur]!=-1) return dp[ind][prev][cur];
        int ans = 1e9;
        if(houses[ind]){
            if(houses[ind] == prev || prev == 21){
                ans = min(ans,solve(ind+1,houses[ind],cur,houses,cost,n,target));
            }
            else{
                ans = min(ans,solve(ind+1,houses[ind],cur+1,houses,cost,n,target));
            }
        }
        else{
            for(int j = 1; j<=n; j++){
                
                if(j == prev || prev == 21){
                    ans = min(ans, cost[ind][j-1] + solve(ind+1,j,cur,houses,cost,n,target));
                }
                else{ 
                    ans = min(ans,cost[ind][j-1] + solve(ind+1,j,cur+1,houses,cost,n,target));
                }
            }
        }
        return dp[ind][prev][cur] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof dp);
        int ans = solve(0,21,1,houses,cost,n,target);
        if(ans >=1e9) return -1;
        return ans;
    }
};

// at each place if it is zero I have n options to fill it
// in the end if we are able to get exactly target neighbourhood we will return 0 else we will return some big amount