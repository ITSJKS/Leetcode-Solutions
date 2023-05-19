class DisjointSet
{

public:
 vector<int> rank, parent, size;
 DisjointSet(int n)
 {
  rank.resize(n + 1, 0);
  parent.resize(n + 1);
  size.resize(n + 1);
  for (int i = 0; i <= n; i++)
  {
   parent[i] = i;
   size[i] = 1;
  }
 }

 int findUPar(int node)
 {
  if (node == parent[node])
   return node;
  return parent[node] = findUPar(parent[node]);
 }

 void unionByRank(int u, int v)
 {
  int ulp_u = findUPar(u);
  int ulp_v = findUPar(v);
  if (ulp_u == ulp_v)
   return;
  if (rank[ulp_u] < rank[ulp_v])
  {
   parent[ulp_u] = ulp_v;
  }
  else if (rank[ulp_v] < rank[ulp_u])
  {
   parent[ulp_v] = ulp_u;
  }
  else
  {
   parent[ulp_v] = ulp_u;
   rank[ulp_u]++;
  }
 }

 void unionBySize(int u, int v)
 {
  int ulp_u = findUPar(u);
  int ulp_v = findUPar(v);
  parent[ulp_v] = ulp_u;
 }
};

class Solution {
public:
     bool Bipartite_graph(int src, vector <int> &color, vector <vector <int>> &graph){
        queue <int> q;
        color[src] = 0;
        q.push(src);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto nbr:graph[f]){
                if(color[nbr]== -1){
                    color[nbr] = !color[f];
                    q.push(nbr);
                }
                else if(color[nbr] == color[f]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> color(n,-1);
        for(int i = 0; i <n; i++){
            if(color[i] == -1)
            if(!Bipartite_graph(i,color,graph)) return false;
        }
        return true;
        
    }
    int bfs(int src, vector <vector <int>> &adj){
        queue <int> q;
        vector <int> vis(adj.size());
        q.push(src);
        int ans = 0;
        vis[src] = 1;
        while(!q.empty()){
            ans++;
            int size = q.size();
            for(int i = 0; i <size; i++){
                int node = q.front();
                q.pop();
                for(auto &nbr:adj[node]){
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr] = 1;
                    }
                }
            }
        }
        return ans;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector <vector <int>> adj(n);
        DisjointSet ds(n);
        for(auto &edge:edges){
            int u = edge[0]-1 , v= edge[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            ds.unionBySize(u,v);
        }
        if(!isBipartite(adj)) return -1;
        // we can find maximum distance for each node, and update their extreme parent, extreme parent will contain maximum distance for each component
        map <int,int> mp;
        for(int i = 0; i <n; i++){
            int d = bfs(i,adj);
            int p = ds.findUPar(i);
            mp[p] = max(mp[p],d);
        }
        int count = 0;
        for(auto &x:mp) count += x.second;
        return count;
    }
};