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
    vector<bool> friendRequests(int n, vector<vector<int>>& rest, vector<vector<int>>& requests) {
        DisjointSet ds(n);
        vector <bool> ans;
        for(auto &x:requests){
            int u  =x[0],  v = x[1];
            int pu = ds.findUPar(u);
            int pv = ds.findUPar(v);
            bool check = true;
            for(auto &y:rest){
                int node1 = y[0] , node2 = y[1];
                node1 = ds.findUPar(node1);
                node2 = ds.findUPar(node2);
                if((node1 == pu && node2 == pv) || (node2 == pu && node1 == pv)){
                    check = false;
                    break;
                }
            }
            if(check){
                ds.unionBySize(u,v);
            }
            ans.push_back(check);
        }
        return ans;
    }
};