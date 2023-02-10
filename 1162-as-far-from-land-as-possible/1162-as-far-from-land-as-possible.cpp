class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector <int> dx= {-1,0,1,0};
        vector <int> dy = {0,-1,0,1};
        queue <pair <int,int>> q;
        int cnt_1 = 0;
        int n = grid.size();
        for(int i = 0; i  < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) q.push({i,j});
                cnt_1 += grid[i][j]==1;
            }
        }
        if(cnt_1 == n*n || cnt_1 == 0) return -1;
        int ans= 0;
        int cnt = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto x = q.front().first, y = q.front().second;
                q.pop();
                grid[x][y] = -1;
                for(int k = 0; k < 4; k++){
                    int x_n = x + dx[k];
                    int y_n =  y + dy[k];
                    if(x_n >=0 && x_n < n && y_n >=0 && y_n<n && grid[x_n][y_n] == 0){
                        grid[x_n][y_n] = -1;
                        ans = max(ans,cnt);
                        q.push({x_n,y_n});
                    }
                }
            }
        cnt++;
        }
    return ans;
    }
};