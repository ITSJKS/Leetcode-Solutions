class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][201];
    int solve(int ind, vector <int> &lc, int finish, int fuel){
        if(fuel < 0) return 0;
        if(dp[ind][fuel]!=-1) return dp[ind][fuel];
        int count = 0;
        if(ind == finish && fuel>=0) count++;
        for(int i = 0; i <lc.size(); i++){
            if(i == ind) continue;
            int f = abs(lc[i] - lc[ind]); 
            count =  (count + solve(i,lc,finish,fuel-f))%mod;
        }
        return dp[ind][fuel] = count%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof dp);
        return solve(start,locations,finish,fuel);
    }
};
// we can try to go from an index start to every index , until our fuel is 0
// which will become 0 after 200 turns 