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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int fp) {
        map <int,unordered_map <int,vector <int>>> mp;
        for(auto &x:meetings){
            int u = x[0],v= x[1],t = x[2];
            mp[t][u].push_back(v);
            mp[t][v].push_back(u);
        }
        DisjointSet ds(n);
        ds.unionBySize(0,fp);
        for(auto &x:mp){
            unordered_set <int> vis;
            queue <int> q;
            for(auto &y:x.second){
                if(vis.count(y.first)  == 0 && ds.findUPar(y.first) == ds.findUPar(fp)){
                    q.push(y.first);
                    vis.insert(y.first);
                    while(q.size()){
                        auto node = q.front();
                        q.pop();
                        for(auto &nbr:x.second[node]){
                            if(vis.count(nbr)) continue;
                            ds.unionBySize(fp,nbr);
                            vis.insert(nbr);
                            q.push(nbr);
                        }
                    }
                    
                }
            }
        }
        vector <int> ans;
        for(int i = 0; i <n; i++){
            if(ds.findUPar(i) == ds.findUPar(fp)) ans.push_back(i);
        }
        return ans;
    }
};