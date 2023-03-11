class Solution {
public:
    vector <int> dx = {-1,1,0,0};
    vector <int> dy = {0,0,1,-1};
    void dfs(int i, int j, vector <vector <int>>&vis,vector <vector <int>>&land,vector <vector<int>>&ans1){
        ans1.push_back({i,j});
        vis[i][j] = 1;
        int n = land.size();
        int m  = land[0].size();
        for(int k = 0; k <4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x>=0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && land[x][y] == 1){
                dfs(x,y,vis,land,ans1);
            }
        }
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n= land.size();
        int m = land[0].size();
        vector <vector <int>> vis(n,vector <int>(m,0));
        vector <vector <int>> ans;
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                if(!vis[i][j]&&land[i][j] == 1){
                    vector <vector <int>> ans1;
                    dfs(i,j,vis,land,ans1);
                    sort(ans1.begin(),ans1.end());
                    ans.push_back(ans1[0]);
                    ans.back().push_back(ans1.back()[0]);
                    ans.back().push_back(ans1.back()[1]);
                }
            }
        }
        return ans;
    }
};