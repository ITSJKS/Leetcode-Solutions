class Solution {
public:
    double visited[1000] = {};
    vector <pair<int,double>> g[1000];
    bool dfs(int src, double val){
        if(visited[src] == 0){
            visited[src] = val;
            for(auto &nbr:g[src]){
                int node = nbr.first;
                double v = nbr.second;
                if(dfs(node,val/v)) return true;
            }
        }
        return abs(visited[src] - val) >= (0.00001);
    }
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map <string,int> ids;
        for(auto &x:equations){
            string u = x[0] , v = x[1];
            if(ids.count(u) == 0) ids[u] = ids.size();
            if(ids.count(v) == 0) ids[v] = ids.size();
        }
        int i = 0;
        for(auto &x:equations){
            int u  = ids[x[0]] , v = ids[x[1]];
            g[u].push_back({v,values[i]});
            g[v].push_back({u,1/values[i]});
            i++;
        }
        for(int i = 0; i <ids.size(); i++){
            if(!visited[i] && dfs(i,1.0)) return true;
        }
        return false;
    }
};

//it is kind of a graph problem
// we will create a graph , when a equation satisfies each other , we will 