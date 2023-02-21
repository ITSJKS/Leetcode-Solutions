class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector <vector <int>> prefix(n+1,vector <int>(m+1,0));
        for(int i = 1; i <=n; i++){
            for(int j = 1; j <=m; j++){
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] -prefix[i-1][j-1] + mat[i-1][j-1];
            }
        }
        auto check = [&](int mid){
            for(int i =mid; i <=n; i++){
                for(int j = mid; j<=m; j++){
                    int sum = prefix[i][j] - prefix[i-mid][j] - prefix[i][j-mid] + prefix[i-mid][j-mid];
                    if(sum <= threshold) return true;
                }
            }
                return false;
        };
        int l = -1, r = min(m,n)+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};