class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int left = -1, right = 1e6;
        vector <int> dir = {1,0,-1,0,1};
        auto check = [&](int mid){
            queue <pair<int,int>> q;
            q.push({0,0});
            vector <vector <int>> vis(n,vector<int>(m,0));
            vis[0][0] = 1;
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                if(x == n - 1 && y == m-1) return true;
                for(int j = 0; j <4; j++){
                    int dx = x + dir[j];
                    int dy = y + dir[j+1];
                    if(dx >=0 && dx < n && dy>=0 && dy < m && vis[dx][dy] == 0 && abs(heights[x][y] - heights[dx][dy])<=mid){
                        q.push({dx,dy});
                        vis[dx][dy] = 1;
                    }
                }
            }
            return false;
        };
        while(right-left>1){
            int mid =  left + (right-left)/2;
            if(check(mid)) right= mid;
            else left = mid;
        }
        return right;
    }
};

// we can search for a particular cost , if we are able to reach the end with values less than that value then we will make our right = mid else we will make our left = mid;