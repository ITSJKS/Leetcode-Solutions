class Solution {
public:
    int adj[403][403];
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector <int> degree(n+1,0);
        memset(adj,0,sizeof adj);
        for(auto &x:edges){
            int u = x[0] , v  = x[1];
            adj[u][v] = 1;
            adj[v][u] = 1;
            degree[u]++;
            degree[v]++;
        }
        auto check = [&](int a, int b){
            if(adj[a][b] || adj[b][a]) return true;
            return false;
        };
        int ans = 1e9;
        for(int i =1 ; i <=n; i++){
            for(int j = i+1; j <=n; j++){
                if(!adj[i][j]) continue;
                for(int k = j+1; k <=n; k++){
                    if(adj[i][k] && adj[j][k]){
                        ans = min(ans,degree[i]+degree[j]+degree[k] - 6);
                    }
                }
            }
        }
        return ans == 1e9?-1:ans;
    }
};

// we can just form all the trio and check their degree 
// degree of a trio =  sum of degree of trio nodes - 6