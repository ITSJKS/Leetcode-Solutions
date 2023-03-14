class Solution {
public:
    int ans = INT_MAX;
    void dfs(vector <pair<int,int>> g[],vector <int> &vis, int src){
        vis[src]= true;
        for(auto nbr:g[src]){
            ans = min(ans,nbr.second);
            if(!vis[nbr.first]){
                dfs(g,vis,nbr.first);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector <int> vis(n+1);
        vector <pair<int,int>> g[n+1];
        for(auto x:roads){
            int u =x[0] , v = x[1], w = x[2];
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        dfs(g,vis,1);
        return ans;
    }
};