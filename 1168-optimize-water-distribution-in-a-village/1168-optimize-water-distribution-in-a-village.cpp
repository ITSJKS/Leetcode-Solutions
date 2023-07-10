class DisjointSet
{
 vector<int> rank, parent, size;

public:
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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        // node 0 is well
        for(int i = 0; i <n; i++){
            pipes.push_back({0,i+1,wells[i]});
        }
        auto cmp = [&](vector <int>&a, vector <int>&b){
            return a[2] < b[2];
        };
        sort(pipes.begin(),pipes.end(),cmp);
        DisjointSet ds(n+1);
        int cost = 0;
        for(auto &x:pipes){
            int u = x[0] , v = x[1] , w = x[2];
            if(ds.findUPar(u)!=ds.findUPar(v)) ds.unionBySize(u,v) , cost += w;
        }
        return cost;
    }
};

// we can do one thing we can create another node called well and connect all other nodes of the graph to that well with cost wells[i-1]
// then we can try to create a minimum spanning tree