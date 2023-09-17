class Solution {
public:
    int dfs(int src , int par, vector <vector <int>>&g, vector <int>&dp, vector <int>&nums,int &id,vector <int>&last){
        int idx = id++;
        int res = nums[src];
        for(auto &nbr:g[src]){
            if(nbr == par) continue;
            res ^= dfs(nbr,src,g,dp,nums,id,last);
        }
        last[idx] = id;
        return dp[idx] = res; 
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector <vector <int>> adj(n);
        for(auto &x:edges){
            int u = x[0] , v  = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector <int> dp(n);
        vector <int> last(n);
        int id = 0;
        int xo_r = dfs(0,-1,adj,dp,nums,id,last);
        int ans = INT_MAX;
        for(int i = 1; i <n; i++){
            for(int j = i+1; j <n; j++){
                int xor_1 = j < last[i] ? xo_r ^ dp[i] : xo_r ^ dp[j] ^ dp[i];
                int xor_2 = j < last[i] ? dp[i] ^ dp[j] : dp[i];
                ans = min(ans,max({xor_1,xor_2,dp[j]})- min({xor_1,xor_2,dp[j]}));
            }
        }
        return ans;
        
    }
};

/*
I will select two edges to remove
When I remove the first edge , The xor of the first component will be total^second 
I can find the xor of the second component using dfs in its subtree
then I can do a dfs in either the first subtree or either second one where my final answer will
be xor of first , second ^ xor in subtree, xor in subtree
or the second one ,first ^ xor in subtree of first , xor in subtree

After that I will either select an edge in the first component or the edge in the second component
*/
