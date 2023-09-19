class Solution {
public:
    int dfs(int src, int par, vector <vector <pair<int,int>>>&g){
        int count = 0;
        for(auto &nbr:g[src]){
            if(nbr.first == par) continue;
            count += nbr.second;
            count += dfs(nbr.first,src, g);
        }
        return count;
    }
    int count = 0;
    void dfs2(int src, int par, vector <vector <pair<int,int>>>&g, int res, int k,set <pair<int,int>> &st){
        if(res >= k) count++;
        for(auto &nbr:g[src]){
            if(nbr.first == par) continue;
            int cnt = res;
            if(nbr.second  == 1) cnt--;
            if(st.count({nbr.first,src})) cnt++;
            dfs2(nbr.first,src,g,cnt,k,st);
        }
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        set <pair<int,int>> st;
        for(auto &x:guesses) st.insert({x[0],x[1]});
        int n = edges.size() + 1;
        vector <vector <pair<int,int>>> g(n);
        for(auto &x:edges){
            int u  =x[0] , v = x[1];
            if(st.count({u,v})){
                g[u].push_back({v,1});
            }
            else{
                g[u].push_back({v,0});
            }
            if(st.count({v,u})){
                g[v].push_back({u,1});
            }
            else{
                g[v].push_back({u,0});
            }
        }
        int res  = dfs(0,-1,g);
        dfs2(0,-1,g,res,k,st);
        return count;
    }
};

/*
we are given guesses where guesses[i] = u,v
where u is parent of v in the tree
brute force will be of doing traversal from every node as root and finding number of guesses that were correct if it was greater >= k we can conclude that it can be one of the root



*/