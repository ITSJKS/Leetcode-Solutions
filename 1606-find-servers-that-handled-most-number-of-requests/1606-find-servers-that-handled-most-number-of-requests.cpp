class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set <int> st;
        set <pair<long long,int>> busy;
        for(int i = 0; i <k; i++){
            st.insert(i);
        }
        int maxi = 0;
        int n = arrival.size();
        unordered_map <int,int> mp;
        for(int i = 0; i < n; i++){
            int cur = arrival[i];
            while(busy.size()){
                auto p = *(busy.begin());
                if(p.first <= cur){
                    st.insert(p.second);
                    busy.erase(p);
                }
                else break;
            }
            int sv = i%k;
            auto it = st.lower_bound(sv);
            if(it!=st.end()){
                busy.insert({cur+load[i],*it});
                mp[*it]++;
                maxi = max(maxi,mp[*it]);
                st.erase(*it);
            }
            else if(st.size()){
                auto it = *st.begin();
                busy.insert({cur+load[i],it});
                mp[it]++;
                maxi = max(maxi,mp[it]);
                st.erase(it);
            }
        }
        vector <int> ans;
        for(auto &x:mp){
            if(x.second == maxi) ans.push_back(x.first);
        }
        return ans;
    }
};

// I can just process those 