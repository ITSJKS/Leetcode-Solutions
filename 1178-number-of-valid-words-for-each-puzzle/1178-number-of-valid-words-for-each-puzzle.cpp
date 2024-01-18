class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map <int,int> mp;
        for(auto &x:words){
            int mask = 0;
            for(auto &y:x){
                mask |= (1)<<(y-'a');
            }
            mp[mask]++;
        }
        vector <int> ans;
        for(auto &x:puzzles){
            set <int> st;
            for(auto &y:x) st.insert(y-'a');
            int m = st.size();
            vector <int> v(st.begin(),st.end());
            int idx = x[0]-'a';
            int res = 0;
            unordered_set <int> vis;
            for(int j = 0; j <(1<<m); j++){
                int cur_mask = 0;
                for(int k = 0; k <m; k++){
                    if(j&(1<<k)) cur_mask |= (1<<(v[k]));
                }
                cur_mask |= (1<<idx);
                if(vis.count(cur_mask)) continue;
                vis.insert(cur_mask);
                if(mp.count(cur_mask)) res += mp[cur_mask];
            }
            ans.push_back(res);
        }
        return ans;
    }
};