class Solution {
public:
    long long dfs(int src, vector <int> adj[],vector <bool> &vis,int seats,long long &fuels){
        vis[src] = true;
        long long people = 0;
        for(auto nbr:adj[src]){
            if(!vis[nbr]){
               long long people_count  = dfs(nbr,adj,vis,seats,fuels);
                if(people_count%seats == 0) fuels += people_count/seats;
                else fuels += people_count/seats + 1;
                people += people_count;
            }
        }
        return people + 1;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector <int> adj[n+1];
        for(auto node:roads){
            int u = node[0] , v = node[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector <bool> vis(n+1,0);
        long long fuels = 0;
        dfs(0,adj,vis,seats,fuels);
        return fuels;
    }
};