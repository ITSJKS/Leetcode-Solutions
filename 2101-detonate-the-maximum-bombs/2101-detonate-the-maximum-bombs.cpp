class Solution {
public:
    void dfs(int ind, vector <vector <int>> &bombs, vector <bool> &vis){
        if(ind == bombs.size()) return;
        int cnt = 1;
        long long x = bombs[ind][0];
        long long y = bombs[ind][1];
        long long r = bombs[ind][2];
        vis[ind] = 1;
        for(int i = 0; i < bombs.size(); i++){
            if(vis[i]) continue;
            long long xx = bombs[i][0];
            long long yy = bombs[i][1];
            long long rr = bombs[i][2];
            double d=sqrt(((xx-x)*(xx-x))+((yy-y)*(yy-y)));
            if(d <= r){
                dfs(i,bombs,vis);
            }
        }
        return;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector <bool> vis(n,0);
        int ans = 0;
        for(int i = 0; i <n; i++){
            dfs(i,bombs,vis);
            int cnt= 0;
            for(int i = 0; i <n; i++){
                cnt += vis[i];
                vis[i] = 0;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};