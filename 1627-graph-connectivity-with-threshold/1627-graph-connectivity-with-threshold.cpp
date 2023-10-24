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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        for(int i = threshold+1; i <=n; i++){
            int prev = i;
            for(int j = 2*i; j <=n; j+=i){
                ds.unionBySize(prev,j);
                prev = j;
            }
        }
        vector <bool> ans;
        for(auto &q:queries){
            int u = q[0] , v = q[1];
            ans.push_back(ds.findUPar(u) == ds.findUPar(v));
        }
        return ans;
    }
};

/*
graph connectivity with threshold
n cities labelled from 1 to n
two cities with labels x and y are directly connected by a bidirectional road if and only if x and y share a common 

10^4
I can do something like this
I can start from threshold + 1 <= n
then for that threshold I can traverse all the multiple of that i and connect them together how can i do that using prev and next one
n + n/2 + n/3 + n/4 ->  nlogn
*/