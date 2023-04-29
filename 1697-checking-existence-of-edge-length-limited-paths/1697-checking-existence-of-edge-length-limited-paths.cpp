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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        auto cmp = [&](vector <int> &v1, vector <int> &v2){
            return v1[2] <= v2[2];
        };
        sort(edgeList.begin(),edgeList.end(),cmp);
        DisjointSet ds(n+1);
        int idx = 0;
        int len = queries.size();
        for(int i = 0; i < len; i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),cmp);
        int m = edgeList.size();
        int ptr = 0;
        vector <bool> ans(len);
        for(int i = 0; i<len; i++){
            int dist = queries[i][2];
            while(ptr < m && edgeList[ptr][2]<dist){
                int u = edgeList[ptr][0] , v  = edgeList[ptr][1];
                ds.unionBySize(u,v);
                ptr++;
            }
            int from = queries[i][0];
            int to = queries[i][1];
            int pos = queries[i][3];
            ans[pos] = (ds.findUPar(from) == ds.findUPar(to));
        }
        return ans;
    }
};