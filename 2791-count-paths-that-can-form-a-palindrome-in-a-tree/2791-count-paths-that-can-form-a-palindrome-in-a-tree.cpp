class Solution {
public:
    long long ans = 0;
    unordered_map <int ,long long> count;
    long long dfs(int src, int mask ,  unordered_map<int, vector<pair<int, char>>> &g, vector <int>&vis){
        vis[src] = 1;
        ans += count[mask];
        for(int j = 0; j <26; j++){
            ans += count[mask^(1<<j)];
        }
        count[mask]++;
        for(auto &nbr:g[src]){
            if(vis[nbr.first] == 0){
                int new_mask = mask ^ (1<<(nbr.second-'a'));
                dfs(nbr.first,new_mask,g,vis);
            }
        }
        return ans;
    }
    long long countPalindromePaths(vector<int>& parent, string s) {
        unordered_map<int, vector<pair<int, char>>> g;
        int n = parent.size();
        for(int i =1 ; i <n; i++){
            int u = i, v = parent[i];
            g[u].push_back({v,s[i]});
            g[v].push_back({u,s[i]});
        }
        vector <int> vis(n);
        dfs(0,0,g,vis);
        return ans;
    }
};
// for each node we can keep a current mask upto that node
// like when we are going 