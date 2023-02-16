
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector <pair <int,int>> st;
        int n = intervals.size();
        int i = 0;
        for(auto x:intervals) st.push_back({x[0],i++});
        sort(st.begin(),st.end());
        vector <int> ans;
        for(auto x:intervals){
            pair <int,int> p = {x[1],0};
            auto it = lower_bound(st.begin(),st.end(),p);
            if(it!=st.end()) ans.push_back(it->second);
            else ans.push_back(-1);
            
        }
        return ans;
    }
};