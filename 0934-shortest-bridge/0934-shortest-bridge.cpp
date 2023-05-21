class Solution {
typedef pair <int,int> pi;
set <pi> island1;
set <pi> island2;
vector <vector <int>> matrix;
vector <vector <bool>> vis; 
int n;
public:
    int check_nbr(int i, int j){
        int count = 0;
        for(int k = 0; k < 4; k++){
            int ni = i + d[k];
            int nj = j + d[k+1];
            if(ni >=0 && ni < n && nj>=0 && nj < n && matrix[ni][nj]){
                count++;
            }
        }
        return count;
    }
    vector <int> d = {-1,0,1,0,-1};
    void dfs(int i, int j, bool first){
        // cout<<i<<" "<<j<<endl;
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int ni = i + d[k];
            int nj = j + d[k+1];
            if(ni >=0 && ni < n && nj>=0 && nj < n && matrix[ni][nj] && !vis[ni][nj]){
                dfs(ni,nj,first);
            }
        }
         int count = check_nbr(i,j);
            if(count <=3){
                if(first) island2.insert({i,j});
                else island1.insert({i,j});
            }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        matrix = grid;
        n = grid.size();
        vis.resize(n,vector <bool>(n,false));
        bool first = false;
        for(int i = 0; i <n; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j]){
                    dfs(i,j,first);
                    first = true;
                }
            }
        }
        int dist = INT_MAX;
        for(auto &x:island1){
            for(auto &y:island2){
                dist = min(dist,abs(x.first-y.first) + abs(x.second - y.second) - 1);
            }
        }
        return dist;
    }
};
// so many way to solve but i m gonna choose my way