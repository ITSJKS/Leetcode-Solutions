class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map <int,int> mp;
        set <int> st;
        for(auto x:nums){
            st.insert(x);
            mp[x]++;
        }
        vector <vector <int>> ans;
        while(st.size()){
            vector <int> temp;
            auto it = st.begin();
            while(it!=st.end()){
                temp.push_back(*it);
                mp[*it]--;
                if(mp[*it] == 0) st.erase(it++);
                else it++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};