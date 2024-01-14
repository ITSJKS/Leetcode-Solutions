class Solution {
public:
    int N; // number of nodes
vector<vector<int>> g; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
bool check;
void dfs(int v, int p = -1) {
     visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                check = true;
            ++children;
        }
    }
    if(p == -1 && children > 1)
        check = true;
}
    void dfs(int src, unordered_set <int> &vis){
        if(vis.count(src)) return;
        vis.insert(src);
        for(auto &nbr:g[src]){
            if(vis.count(nbr) == 0) dfs(nbr,vis);
        }
    }
    vector <int> dir = {-1,0,1,0,-1};
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        N = n*m;
        g.resize(N);
        unordered_set <int> st;
        for(int i  =0; i <n; i++){
            for(int j = 0; j <m; j++){
                if(grid[i][j] == 0) continue;
                st.insert(i*m + j);
                for(int k = 0; k <4; k++){
                    int ni = i + dir[k];
                    int nj = j + dir[k+1];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1){
                        g[i*m + j].push_back(ni*m + nj);
                        st.insert(ni*m + j);
                    }
                }
            }
        }
        unordered_set <int> vis;
        int count = 0;
        for(auto &x:st){
            if(vis.count(x)) continue;
            dfs(x,vis);
            count++;
        }
        if(count!=1) return 0;
        else if(st.size() == 1) return 1;
        else if(st.size() == 2) return 2;
        check = false;
        timer = 0;
        visited.assign(N, false);
        tin.assign(N, -1);
        low.assign(N, -1);
        for (auto &x:st) {
            if (!visited[x])
                dfs(x);
    }
        if(check) return 1;
        return 2;
    }
};
// if there is only one component
// we can find indices of the island and then check for bridges in the graph
// if there is a bridge then our answer will be 1 else our answer will be 2