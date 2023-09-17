class Solution {
public:
    void dfs(int src, int par, vector <vector <int>>&g, map <int,vector <pair<int,int>>>&mp, vector <int> &ans,vector <int>&nums,int level){
        int val = nums[src];
        int cur = -1;
        int lvl_ = -1;
        for(int j = 1; j <=50; j++){
            if(gcd(j,val) == 1){
                if(mp[j].size()){
                    int v = mp[j].back().first;
                    int lvl = mp[j].back().second;
                    if(lvl > lvl_) cur = v, lvl_ = lvl;
                }
            }
        }
        ans[src] = cur;
        mp[val].push_back({src,level});
        for(auto &nbr:g[src]){
            if(nbr == par) continue;
            dfs(nbr,src,g,mp,ans,nums,level+1);
        }
        mp[val].pop_back();
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector <vector <int>> g(n);
        for(auto &edge:edges){
            int u = edge[0] , v= edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        map <int,vector <pair<int,int>>> mp;
        vector <int> ans(n);
        dfs(0,-1,g,mp,ans,nums,0);
        return ans;
    }
};