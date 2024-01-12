class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
         set <int> st;
        set <pair<long long,int>> busy;
        for(int i = 0; i <n; i++){
            st.insert(i);
        }
        sort(meetings.begin(),meetings.end());
        int maxi = 0;
        int m = meetings.size();
        unordered_map <int,int> mp;
        long long cur = 0;
        for(int i = 0; i < m; i++){
            cur = max(cur,1ll*meetings[i][0]);
            while(busy.size()){
                auto p = *(busy.begin());
                if(p.first <= cur){
                    st.insert(p.second);
                    busy.erase(p);
                }
                else break;
            }
            int sv = i%n;
            if(st.size() == 0){
                auto q = *(busy.begin());
                cur = q.first;
                while(busy.size()){
                auto p = *(busy.begin());
                if(p.first <= cur){
                    st.insert(p.second);
                    busy.erase(p);
                }
                else break;
            }
            }
            auto it = *st.begin();
                busy.insert({cur + meetings[i][1]-meetings[i][0],it});
                mp[it]++;
                maxi = max(maxi,mp[it]);
                st.erase(it);
        }
        vector <int> ans;
        for(auto &x:mp){
            if(x.second == maxi) ans.push_back(x.first);
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};