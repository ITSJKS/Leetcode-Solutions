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
// size 0 , one option f(0) = 1;
// subset is of size 1
// i have two option take or not take f(1) = 2;
// for f(2), i can either not take it that way i have current count as f(1) , or i can combine the current element with f(i-2) so f(0)
class Solution {
    long long solve(int num){
        if(num == 0) return num;
        long long first = 1;
        long long second = 2;
        for(int i = 2; i <=num; i++){
            long long cur = first + second;
            first = second;
            second = cur;
        }
        return second;
    }
public:
    long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        DisjointSet ds(n);
        for(int i = 0; i <n; i++){
            for(int j = i+1; j <n; j++){
                if((nums[j] - nums[i]) == k) ds.unionBySize(i,j);
            }
        }
        long long res = 1;
        for(int i = 0; i <n; i++){
            if(ds.findUPar(i) == i) res= res*1ll*solve(ds.size[i]);
        }
        return res;
    }
};