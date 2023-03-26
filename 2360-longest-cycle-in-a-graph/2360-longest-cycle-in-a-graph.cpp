class Solution {
public:
    int ans = -1;
    void dfs(int src,vector <int> &vis,unordered_map <int,int> &mp,vector <int> &edges){
        vis[src] = true;
        int x = edges[src];
            if(x!=-1 && vis[x]==false){
                mp[x] = mp[src]+1;
                dfs(x,vis,mp,edges);
            }
            else if(x!=-1 && mp.count(x)){
                ans = max(ans,mp[src] - mp[x]+1);
            }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector <int> vis(n);
        for(int i = 0; i <n; i++){
            if(!vis[i]){
                unordered_map <int,int> mp;
                mp[i] = 0;
                dfs(i,vis,mp,edges);
            }
        }
        return ans;
    }
};