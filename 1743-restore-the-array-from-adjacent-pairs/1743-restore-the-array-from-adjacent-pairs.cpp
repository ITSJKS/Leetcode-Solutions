class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        map <int,vector <int>> idx;
        for(auto &x:ap){
            int u = x[0] , v= x[1];
            idx[u].push_back(v);
            idx[v].push_back(u);
        }
        int n = ap.size() +1;
        vector <int> ans;
        for(auto &x:idx){
            if(x.second.size() == 1){
                ans.push_back(x.first);
                ans.push_back(x.second.back());
                break;
            }
        }
        while(ans.size() < n){
            int last =ans.back();
            int prev = ans[ans.size()-2];
            auto &cur = idx[last];
            if(cur[0]!=prev) ans.push_back(cur[0]);
            else ans.push_back(cur.back());
        }
        return ans;
    }
};

// there will be two number which exist just once which will be our end point , then we can fix their point and try to form our original array using them