class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& cBox, vector<int>& iBox) {
        int n = status.size();
        int count = 0;
        vector <int> vis(n);
        queue <int> q;
        unordered_set <int> keys_st;
        unordered_set <int> boxes;
        for(auto &x:iBox){
            if(status[x]){
                q.push(x);
                vis[x] = 1;
            }
            else{
                boxes.insert(x);
            }
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            count += candies[f];
            for(auto &x:keys[f]){
                if(vis[x]) continue;
                if(boxes.count(x)){
                    q.push(x);
                    boxes.erase(x);
                    vis[x] = 1;
                }
                else{
                    keys_st.insert(x);
                }
            }
            for(auto &b:cBox[f]){
                if(vis[b]) continue;
                if(status[b]){
                    q.push(b);
                    vis[b] = 1;
                    if(keys_st.count(b)) keys_st.erase(b);
                    if(boxes.count(b)) boxes.erase(b);
                }
                else if(keys_st.count(b)){
                    q.push(b);
                    keys_st.erase(b);
                    vis[b] = 1;
                }
                else{
                    boxes.insert(b);
                }
            }
        }
        return count;
    }
};