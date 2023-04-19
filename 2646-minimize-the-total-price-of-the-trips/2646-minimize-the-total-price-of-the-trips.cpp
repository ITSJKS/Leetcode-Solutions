class Solution {
public:
    vector <int> count;
    int dp[51][2];
    void find_node_count(int node, int end, vector <vector<int>>&g, vector <int> &path, int par){
        path.push_back(node);
        if(node == end){
            for(auto x:path){
                count[x]++;
            }
            path.pop_back();
            return;
        }
        for(auto &nbr:g[node]){
            if(nbr == par) continue;
            find_node_count(nbr,end,g,path,node);
        }
        path.pop_back();
    }
    int solve(int node,vector <vector <int>> &g, vector <int> &price, int par, bool taken ){
        if(dp[node][taken]!=-1) return dp[node][taken];
        int reduced_price = count[node]*(price[node]/2);
        int org_price = count[node]*price[node];
        for(auto &nbr:g[node]){
            if(nbr == par) continue;
            org_price += solve(nbr,g,price,node,0);
        }
        if(taken) return org_price;
        for(auto &nbr:g[node]){
            if(nbr == par) continue;
         reduced_price += solve(nbr,g,price,node,1);
        }
        return dp[node][taken] = min(reduced_price,org_price);
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        memset(dp,-1,sizeof(dp));
        count.assign(n,0);
        vector <vector <int>> g(n);
        for(auto &x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        for(auto &x:trips){
            int src = x[0] , dest = x[1];
            vector <int> path;
            find_node_count(src,dest,g,path,-1);
        }
        // for(auto x:count) cout<<x<<" ";
        return solve(0,g,price,-1,0);
        return 0;
    }
};