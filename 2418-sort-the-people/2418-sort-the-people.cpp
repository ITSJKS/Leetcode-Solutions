class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector <pair <int,string>> p;
        for(int i = 0; i <names.size(); i++){
            p.push_back({heights[i],names[i]});
        }
        sort(p.begin(),p.end());
        vector <string> ans;
        for(auto x:p){
            ans.push_back(x.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};