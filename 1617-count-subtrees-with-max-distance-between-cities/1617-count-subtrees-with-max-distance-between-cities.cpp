class Solution {
public:
    int ans = 0;
    int dfs(int src, vector <vector <int>> &adj, set <int> &subtree, set <int> &vis){
        vis.insert(src);
        int m1 = 0;
        int m2 = 0;
        for(auto &nbr:adj[src]){
            if(subtree.count(nbr) && vis.count(nbr) == 0){
                int d = dfs(nbr,adj,subtree,vis);
                if(d > m1){
                    m2 = m1;
                    m1 = d;
                }
                else if(d > m2){
                    m2 = d;
                }
            }
        }
        ans = max(ans,m1 + m2);
        return m1 + 1;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        // create graph
        vector <int> res(n-1);
        vector <vector <int>> adj(n+1);
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int state = 0; state < (1<<n); state++){
            set <int> subtree;
            for(int i = 0; i <n; i++){
                if((state>>i)&1) subtree.insert(i+1);
            }
            int cnt_edge = 0;
            for(auto &x:edges){
                if(subtree.count(x[0]) && subtree.count(x[1])) cnt_edge++;
            }
            if(cnt_edge < 1 || subtree.size() !=  cnt_edge + 1) continue;
            set <int> vis;
            ans = 0;
            int src = *subtree.begin();
            dfs(src, adj,subtree,vis);
            if(ans>0) res[ans-1]++;
        }
        return res;
    }
};

// Concepts i revised for this questions
/*
1. Bitmasking 
2. Tree Diameter using both 2 maximum and two bfs traversal
3. Tree Basics
*/