class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map <int,vector <int>> mp;
        int i = 0;
        for(auto x:g) mp[x].push_back(i++);
        vector <vector<int>> ans;
        for(auto x:mp){
            int s = x.first;
            int count = 1;
            ans.push_back({});
            for(auto y:x.second){
                if(count > s){
                    ans.push_back({});
                    count = 1;
                }
                ans.back().push_back(y);
                count++;
            }
        }
        return ans;
        
    }
};