class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n =values.size();
        vector <vector <pair<int,int>>> g(n);
        for(auto &x:edges){
            int u = x[0] ,  v= x[1] , w = x[2];
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        int ans = values[0];
        vector <int> vis(n,0);
        dfs(0,g,ans,values,vis,0,0,maxTime);
        return ans;
    }
    void dfs(int src, vector <vector <pair<int,int>>> &g, int &ans, vector <int> &values, vector <int> &vis,int score, int time, int maxTime){
        if(time > maxTime) return;
        if(vis[src] == 0) score += values[src];
        vis[src]++;
        if(src == 0) ans = max(ans,score);
        for(auto &nbr:g[src]){
            int to = nbr.first;
            int cost = nbr.second;
            int newTime = time + cost;
            dfs(to,g,ans,values,vis,score, newTime,maxTime);
        }
        vis[src]--;
    }
};