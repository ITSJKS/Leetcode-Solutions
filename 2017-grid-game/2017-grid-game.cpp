class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector <long long> prefix1(n+1),prefix2(n+1);
        for(int i = 0; i <n; i++){
            prefix1[i+1] = prefix1[i] + grid[0][i];
            prefix2[i+1] = prefix2[i] + grid[1][i];
        }
        long long ans = 1e11;
        for(int i =1; i <=n; i++){
            long long sum1 = prefix1[n] - prefix1[i];
            long long sum2 = prefix2[i-1];
            ans = min(ans,max(sum1,sum2));
        }
        return ans;
    }
};