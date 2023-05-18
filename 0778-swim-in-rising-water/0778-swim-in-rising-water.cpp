class Solution
{
    public:
        vector<int> dx = { -1,
            0,
            1,
            0
        };
    vector<int> dy = { 0,
        -1,
        0,
        1
    };
    bool dfs(int maxi, int i, int j, vector<vector < int>> &grid)
    {
        int n = grid.size();
        if (i == n - 1 && j == n - 1) return grid[i][j] <= maxi;
        if (i >= n || j >= n) return false;
        int val = grid[i][j];
        if (val > maxi) return false;
        grid[i][j] = -1;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] != -1)
            {
                if (dfs(maxi, ni, nj, grid)) return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector < int>> &grid)
    {
       	// let's do binary search on 0 and n*n
        int n = grid.size();
        if (n == 1) return 0;
        auto check =[&](int mid)
        {
            vector <vector <int>> grid1 = grid;
            return dfs(mid, 0, 0, grid1);
        };
        int l = 0, r = n * n;
        while (r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};