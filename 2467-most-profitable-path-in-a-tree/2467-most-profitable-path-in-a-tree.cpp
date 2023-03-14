class Solution {
public:
    int n;
    vector <int> find_path(int src, int bob, vector <int> g[]){
        vector <int> path;
        vector <int> parent(n);
        queue <int> q;
        vector <int> vis(n);
        parent[src] = -1;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == bob) break;
            for(auto nbr:g[node]){
                if(!vis[nbr]){
                    vis[nbr] = 1;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
    while(parent[bob]!=-1){
        path.push_back(bob);
        bob = parent[bob];
    }
        path.push_back(bob);
        reverse(path.begin(),path.end());
        return path;
    }
    
    int dfs(int src, vector <int> g[] , vector <int> &vis,vector <int> &amount){
        int maxi = -1e7;
        vis[src] = 1;
        bool check = true;
        for(auto nbr:g[src]){
            if(!vis[nbr]){
                check = false;
                maxi = max(maxi,dfs(nbr,g,vis,amount));
            }
        }
        if(check) return amount[src];
        return maxi  +  amount[src];
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n = edges.size() + 1;
        vector <int> g[n];
        for(auto x:edges){
            int u = x[0] , v = x[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector <int> path = find_path(0,bob,g);
        int i =0 , j = path.size() - 1;
        while(i <= j){
            if(i == j){
                amount[path[i]]/=2;
            }
            else{
                amount[path[j]] = 0;
            }
            i++;
            j--;
        }
        // for(auto x:amount) cout<<x<<" ";
        vector <int> vis(n);
        return dfs(0,g,vis,amount);
    }
};

/*

Rough:-
My understanding is we can handle the paths as two types
one that lies in the path from 0 to bob , we can handle this path seperately then we can consider the given graph as a normal one and find the most profitable path from root to leaf node
Intuition:-

Explanation:-

*/
