class Solution {
public:
    void dfs(int src,unordered_map <int,vector <int>> &mp, vector <int> &res){
        while(mp[src].size()){
            auto node = mp[src].back();
            mp[src].pop_back();
            dfs(node,mp,res);
        }
        res.push_back(src);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map <int,vector <int>> mp;
        unordered_map <int,int> in,out;
        for(auto &x:pairs){
            int u = x[0], v = x[1];
            in[v]++;
            out[u]++;
            mp[u].push_back(v);
        }
        vector <vector <int>> ans;
        int start = -1; 
        for(auto &x:mp){
            int node = x.first;
            if(out[node]-in[node] == 1){
                start = node;
            }
        }
        if(start == -1){
            auto x = *mp.begin();
            start = x.first;
        }
        vector <int> res;
        dfs(start,mp,res);
        reverse(res.begin(),res.end());
        for(int i = 0; i <res.size()-1; i++){
            ans.push_back({res[i],res[i+1]});
        }
        return ans;
        
    }
};