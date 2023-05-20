typedef pair<int, pair<int,int>> ppi;
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int count = 0;
        vector <pair<int,int>> q;
        for(int i = 0; i <queries.size(); i++){
            q.push_back({queries[i],i});
        }
        int qs = q.size();
        sort(q.begin(),q.end());
        int n = grid.size();
        int m = grid[0].size();
        auto cmp = [&](vector <int> &a, vector <int> &b){
            return a[0] < b[0];
        };
        priority_queue <pair<int,pair<int,int>>,vector <ppi>,greater<ppi>> pq;
        vector <int> ans(qs,0);
        pq.push({grid[0][0],{0,0}});
        int idx = 0;
        // for(auto &x:q){
        //     if(x.first > grid[0][0]){
        //         pq.push({grid[0][0],{0,0}});
        //         count++;
        //         break;
        //     }
        //     else{
        //         idx++;
        //         ans[x.second] = 0;
        //     }
        // }
        vector <vector <int>> vis(n,vector <int> (m,0));
        vis[0][0] = 1;
        vector <int> dx = {-1,0,1,0};
        vector <int> dy = {0,1,0,-1};
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int num = top.first;
            int x = top.second.first;
            int y = top.second.second;
            while(idx < qs && q[idx].first <= num){
                ans[q[idx].second] = count;
                idx++;
            }
            if(idx == qs) return ans;
            count++;
            ans[q[idx].second] = count;
            for(int j = 0; j < 4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx >=0 && nx < n && ny >=0 && ny < m && vis[nx][ny] == 0){
                    pq.push({grid[nx][ny],{nx,ny}});
                    vis[nx][ny] = 1;
                }
            }
        }
        while(idx < qs){
                ans[q[idx].second] = count;
            idx++;
            }
        return ans;
    }
};