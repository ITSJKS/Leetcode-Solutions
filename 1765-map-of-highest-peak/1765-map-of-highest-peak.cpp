class Solution {
public:
    vector <int> dx = {-1,0,1,0};
    vector <int> dy = {0,1,0,-1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue <pair <int,int>> q;
        vector <vector <int>> h(n,vector <int>(m,-1));
        for(int i = 0; i <n; i++){
            for(int j  = 0;j <m; j++){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                    h[i][j] = 0;
                }
            }
        }
        int count = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i <size; i++){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && h[nx][ny] == -1){
                        h[nx][ny] = count;
                        q.push({nx,ny});
                    }
                }
            }
            count++;
        }
        return h;
    }
};