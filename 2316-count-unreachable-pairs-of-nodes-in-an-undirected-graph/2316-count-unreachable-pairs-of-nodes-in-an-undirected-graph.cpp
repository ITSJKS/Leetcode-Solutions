class Solution {
public:
    long long count_nodes(int src, vector <int> g[],vector <int> &vis){
        vis[src] = 1;
        int count = 1;
        for(auto nbr:g[src]){
            if(!vis[nbr]) count += count_nodes(nbr,g,vis);
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector <int> g[n];
        for(auto edge:edges){
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        long long ans = 0;
        vector <int> vis(n);
        int total_node  = n;
        for(int i = 0; i <n; i++){
            if(!vis[i]){
                long long y = count_nodes(i,g,vis);
                long long rem = total_node - y;
                ans += (y*1ll*rem);
                total_node -= y;
            }
        }
        return ans;
    }
};