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
  if (ulp_u == ulp_v)
   return;
  if (size[ulp_u] < size[ulp_v])
  {
   parent[ulp_u] = ulp_v;
   size[ulp_v] += size[ulp_u];
  }
  else
  {
   parent[ulp_v] = ulp_u;
   size[ulp_u] += size[ulp_v];
  }
 }
};

class Solution {
public:
    int dist(vector <int> &a, vector <int> &b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
        auto cmp = [&](vector <int>&a, vector <int>&b){
            return a[2] < b[2];
        };
        int cost =0 ;
        sort(connections.begin(),connections.end(),cmp);
        DisjointSet ds(n);
        for(auto &x:connections){
            int u = x[0] , v  =x[1],w= x[2];
            if(ds.findUPar(u)!=ds.findUPar(v)){
                ds.unionBySize(u,v);
                cost += w;
            }
        }
        if(ds.size[ds.findUPar(1)]!=n) return -1;
        return cost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector <vector <int>> edges;
        for(int i = 0; i <n; i++){
            for(int j = i+1; j <n; j++){
                edges.push_back({i,j,dist(points[i],points[j])});
            }
        }
        return minimumCost(n,edges);
    }
};