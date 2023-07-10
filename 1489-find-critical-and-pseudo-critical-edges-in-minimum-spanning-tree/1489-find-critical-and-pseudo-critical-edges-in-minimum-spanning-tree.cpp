#include <bits/stdc++.h>
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
int getMst(int n, vector <vector <int>> &edges, vector <int>cur_edge, int del_idx){
	DisjointSet ds(n);
	int weight = 0;
	if(cur_edge.size()){
		int u  =cur_edge[0];
		int v = cur_edge[1];
		int w = cur_edge[2];
		ds.unionBySize(u,v);
		weight += w;
	}
	for(auto &edge:edges){
		int u  =edge[0];
		int v = edge[1];
		int w = edge[2];
		int idx = edge[3];
		if(idx == del_idx) continue;
		if(ds.findUPar(u) != ds.findUPar(v)){
			weight += w;
			ds.unionBySize(u,v);
		}
	}
	int root = ds.findUPar(0);
	for(int i = 0; i <n; i++){
		if(ds.findUPar(i)!=root) return INT_MAX;
	}
	return weight;
}
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Write your code here.
	for(int i = 0; i <edges.size(); i++){
		edges[i].push_back(i);
	}
	auto cmp = [&](vector <int> &a, vector <int>&b){
		return a[2] < b[2];
	};
	sort(edges.begin(),edges.end(),cmp);
	int mstw = getMst(n,edges,{},-1);
	vector <int> critical,pseudo;
	for(auto &cur_edge:edges){
		int u  =cur_edge[0];
		int v = cur_edge[1];
		int w = cur_edge[2];
		int idx = cur_edge[3];
		int cur_w = getMst(n,edges,{},idx);
		if(cur_w > mstw) critical.push_back(idx);
		else if(getMst(n,edges,cur_edge,-1) == mstw) pseudo.push_back(idx);
	}
	return {critical,pseudo};
    }
};
