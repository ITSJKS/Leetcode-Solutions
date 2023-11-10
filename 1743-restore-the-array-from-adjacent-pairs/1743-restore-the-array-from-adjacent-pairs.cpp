class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map <int,vector <int>> mp;
        int n = adjacentPairs.size()+1;
        vector <int> ans;
        for(auto &x:adjacentPairs){
            int u = x[0] , v=  x[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
       }
       int start = -1;
       for(auto &x:mp){
           if(x.second.size() == 1){
               start = x.first;
               break;
           }
       }
       ans.push_back(start);
       int prev = -1e9;
        while(ans.size()<mp.size())
        for(auto &x:mp[start]){
                if(x!=prev){
                    ans.push_back(x);
                    prev = start;
                    start = x;
                    break;
                }
        }
        return ans;
    }
};