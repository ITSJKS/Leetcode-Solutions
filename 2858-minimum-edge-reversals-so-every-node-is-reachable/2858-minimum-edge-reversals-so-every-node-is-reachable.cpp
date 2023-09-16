class Solution {
public:
    int dfs(int src, int par, vector <vector <int>>&g,vector <vector <int>>&rev_g){
        int count_down = 0;
        for(auto &nbr:g[src]){
            if(nbr == par) continue;
            count_down += dfs(nbr,src,g,rev_g);
        }
        for(auto &nbr:rev_g[src]){
            if(nbr == par) continue;
            count_down++;
            count_down += dfs(nbr,src,g,rev_g);
        }
        return count_down;
    }
    vector <int> ans;
    void dfs2(int src, int par, vector <vector <int>>&g,vector <vector<int>>&rev_g,int cnt){
        ans[src] = cnt;
        for(auto &nbr:g[src]){
            if(nbr != par){
                dfs2(nbr,src,g,rev_g,cnt+1);
            }
        }
        for(auto &nbr:rev_g[src]){
            if(nbr == par) continue;
            dfs2(nbr,src,g,rev_g,cnt-1);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        ans.resize(n,0);
        vector <vector <int>> g(n);
        vector <vector <int>> rev_g(n);
        for(auto &x:edges){
            int u = x[0] , v= x[1];
            g[u].push_back(v);
            rev_g[v].push_back(u);
        }
        ans[0] = dfs(0,-1,g,rev_g);
        dfs2(0,-1,g,rev_g,ans[0]);
        return ans;
    }
};

// I need number of edges in the subtree which are of opposite sign
// I need number of 