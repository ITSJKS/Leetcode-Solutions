class Solution {
public:
    int dp[14][1<<13];
    int solve(int src, int mask, vector <vector <int>>&g,vector <int> &nums){
        if(mask == 0) return 1;
        if(dp[src][mask]!=-1) return dp[src][mask];
        unordered_set <int> vis;
        int ans = 0;
        for(auto &nbr:g[src]){
            if(mask&(1<<nbr) && vis.count(nums[nbr]) == 0){
                ans += solve(nbr,mask ^ (1<<nbr),g,nums);
                vis.insert(nums[nbr]);
            }
        }
        return dp[src][mask] = ans;
    }
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        vector <vector <int>> g(n+1);
        for(int i = 0; i <n; i++){
            for(int j = i+1; j <n; j++){
                int sum = nums[i] + nums[j];
                int sq = sqrt(sum);
                if(sq*sq == sum){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        for(int i = 0; i <n; i++){
            g[n].push_back(i);
        }
        memset(dp,-1,sizeof dp);
        return solve(n,(1<<n)-1,g,nums);
    }
};