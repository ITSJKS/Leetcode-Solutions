class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& cT, vector<string>& ids, vector<int>& views) {
        unordered_map <string,map <string,int>> mp;
        map <string,long long> mp1;
        int n = cT.size();
        long long h_view  = 0;
        for(int i = 0; i <n; i++){
            string cT1 = cT[i];
            string id = ids[i];
            int view = views[i];
            mp[cT1][id]= view;
            mp1[cT1]+=view;
            h_view= max(h_view,mp1[cT1]);
        }
        vector <vector <string>> ans;
        for(auto x:mp1){
            if(x.second == h_view){
                string s = x.first;
                int view = -1;
                string id = "";
                for(auto y:mp[s]){
                    if(y.second > view){
                        view = y.second;
                        id = y.first;
                    }
                }
                ans.push_back({s,id});
            }
        }
        return ans;
    }
};