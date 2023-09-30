const int sz=1e5+1;
bool PrimeSieve[sz+5];   // 1e6+5
bool check = true;
void buildSieve(){
    for(int i=2;i<=sz;i++)    PrimeSieve[i]=1;
    PrimeSieve[0]=0;// 
    PrimeSieve[1]=0;    // 1 is neither prime nor composite 
    for(int i=2;i<sz;i++){
        if(PrimeSieve[i]==0)    continue;       // the current number itself is composite 
        for(int j=2;j*i<sz;j++){
            PrimeSieve[i*j]=0;
        }
    }
    check = false;
}

/// DSU
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
long long solve(int n,vector <vector <int>> &edges)
{
  vector <int> adj[n+1];
  DisjointSet ds(n);
  for(int i = 1; i <n; i++){
    int u,v;
    u = edges[i-1][0];
    v=  edges[i-1][1];
    if(!PrimeSieve[u] && !PrimeSieve[v]){
      ds.unionBySize(u,v);
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long ans = 0;
  vector <int> v;
  for(int i = 1; i<=n; i++){
    if(PrimeSieve[i]) v.push_back(i);
  }
  // vector <int> size(n+1,0);
  for(auto &i:v){
    if(PrimeSieve[i]){
      long long sum = 0;
      long long res = 0;
      for(auto &nbr:adj[i]){
        if(PrimeSieve[nbr]) continue;
        int ulp = ds.findUPar(nbr);
        sum += ds.size[ulp];
      }
      for(auto &nbr:adj[i]){
        if(PrimeSieve[nbr]) continue;
        int ulp = ds.findUPar(nbr);
        res += ds.size[ulp]*1ll*(sum-ds.size[ulp]);
      }
      ans += sum + (res/2);
    }
  }
  return ans;
}
class Solution {
public:
    
    long long countPaths(int n, vector<vector<int>>& edges) {
        if(check) buildSieve();
        return solve(n,edges);
    }
};

/*
there will be 1000 prime numbers between u and v , so we 

*/