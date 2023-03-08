// Like 3 and 21 are connected as well as 7 and 21
// we can swap anything in one island with anyting in the same island , to swap between two island we can check if these two island are connected
// so for every num which is not in correct place we will try to put it in right places using swaps
// 7 21 , 3 --> 21
// everything is connected
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
    vector <int> spf;
    bool gcdSort(vector<int>& nums) {
        vector <int> v(nums.begin(),nums.end());
        int n = nums.size();
        sort(v.begin(),v.end());
        int maxi = *max_element(nums.begin(),nums.end());
        sieve(maxi+1);
        DisjointSet ds(maxi+1);
        for(auto num:nums){
            for(auto factor:prime_factors(num)){
                ds.unionBySize(num,factor);
            }
        }
        for(int i = 0; i <n; i++){
            int ulp = ds.findUPar(nums[i]);
            int ulp2 = ds.findUPar(v[i]);
            if(ulp!=ulp2) return false;
        }
        return true;
    }
    void sieve(int n){
        spf.resize(n);
        for(int i = 2; i <n; i++){
            spf[i] = i;
        }
        for(int i =2; i*i <n; i++){
            for(int j = i*i; j<n; j+=i){
                if(spf[j]>i){
                    spf[j] = i;
                }
            }
        }
    }
    vector <int> prime_factors(int n){
        vector <int> ans;
        while(n>1){
            ans.push_back(spf[n]);
            n/=spf[n];
        }
        return ans;
    }
};