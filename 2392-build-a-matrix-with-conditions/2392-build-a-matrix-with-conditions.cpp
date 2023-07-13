
class Solution {
public:
    vector <int> topo(int n,vector <vector <int>>&edges){
        vector <vector <int>> g(n+1);
        vector <int> degree(n+1,0);
        for(auto &x:edges){
            int u = x[0],v = x[1];
            g[u].push_back(v);
            degree[v]++;
        }
        queue <int> q;
        for(int i = 1; i <=n; i++){
            if(degree[i] == 0) q.push(i);
        }
        vector <int> order;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            order.push_back(f);
            for(auto &nbr:g[f]){
                degree[nbr]--;
                if(degree[nbr] == 0) q.push(nbr);
            }
        }
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowC, vector<vector<int>>& colC) {
        vector <int> row = topo(k,rowC);
        vector <int> col = topo(k,colC);
        // for(auto &x:col) cout<<x<<" ";
        if(row.size()!= k || col.size()!=k) return {};
        vector <vector <int>>res(k,vector <int>(k,0));
        vector <int> row_idx(k+1),col_idx(k+1);
        for(int i = 0; i <k; i++){
            row_idx[row[i]] = i;
            col_idx[col[i]] = i;
        }
        for(int i = 0; i <k; i++){
            res[row_idx[i+1]][col_idx[i+1]] = i+1;
        }
        // My final matrix row's should be in order of row
        return res;
    }
};
// 160000 nodes
// for each nodes there will be some condition based on rowC and colC 
// we can apply topological sort by converting the 