class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set <int> winner;
        set <int> losser;
        map <int,int> loss_count;
        for(auto x:matches){
            int w = x[0];
            int l = x[1];
            winner.insert(w);
            losser.insert(l);
            loss_count[l]++;
        }
        vector <vector <int>> ans(2);
        for(auto x:winner){
            if(losser.find(x)==losser.end()) ans[0].push_back(x);
        }
        for(auto x:loss_count){
            if(x.second == 1) ans[1].push_back(x.first);
        }
        return ans;
    }
    
};