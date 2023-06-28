class Solution {
public:
    double find_log(double d)
{
    return log10(d);
}
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector <vector<pair<int,double>>> adj(n);
        int i = 0;
        for(auto &x:edges){
            int u = x[0] , v = x[1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
            i++;
        }
        vector<int> seen(n, 0);
        priority_queue<pair<double, int>> q;
        q.push({(double)1.0, start});
        
        vector<double> mx(n, (double)0.0);
        mx[start] = 1.0;
        
        while(!q.empty()) {
            auto top = q.top();
            q.pop();
            double proba = top.first;
            int node = top.second;
            if(!seen[node]) {
                seen[node]++;
                for(auto &to: adj[node]) {
                    if (mx[to.first] < to.second*proba) {
                        mx[to.first] = to.second*proba;
						q.push({mx[to.first], to.first});
                    }
                }
            }
        }
        return mx[end];
    }
};