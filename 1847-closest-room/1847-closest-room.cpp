class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        auto cmp = [&](vector <int>&a, vector <int>&b){
            return a[1] == b[1]?a[0] < b[0]:a[1] < b[1];
        };
        sort(rooms.begin(),rooms.end(),cmp);
        int n  = rooms.size();
        int q = queries.size();
        for(int i = 0; i <q; i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),cmp);
        int j = n-1;
        set <int> st;
        vector <int> res(q);
        for(int i=q-1; i>=0; i--){
            int num = queries[i][1],id = queries[i][0], idx = queries[i][2];
            while(j>=0 && rooms[j][1] >= num){
                st.insert(rooms[j][0]);
                j--;
            }
            int ans = 1e9;
            int ans_id = 1e9;
            if(st.size()){
            auto it = st.lower_bound(id);
                if(it!=st.end()){
                    int diff = *it - id;
                    ans = min(ans,diff);
                    ans_id = min(ans_id,*it);
                }
                if(it!=st.begin()){
                    it--;
                    int diff1 = id - *it;
                    if(diff1 < ans){
                        ans = diff1;
                        ans_id = *it;
                    }
                    else if(diff1 == ans){
                        ans_id = min(ans_id,*it);
                    }
                }
                res[idx] = ans_id;
            }
            else res[idx] = -1;
        }
        return res;
    }
};