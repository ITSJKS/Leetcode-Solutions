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
bool check(string &s, string &t){
    int n =s.size();
    int count = 0;
    for(int i = 0; i<n; i++){
        if(s[i]!=t[i]) count++;
    }
    return (count == 0 || count == 2);
}
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet ds(n);
        for(int i =0 ; i < n; i++){
            for(int j = i+1; j <n; j++){
                if(check(strs[i],strs[j])){
                    ds.unionBySize(i,j);
                }
            }
        }
        int count = 0;
        for(int i = 0; i <n; i++){
            count += (ds.parent[i] == i);
        }
        return count;
    }
};

// we can dsu but how
// tars rats arts star
// we have n = 300 so even n^3 should work
// we can traverse the string array , 
// for every element we can find element in the array which are 2 swap away