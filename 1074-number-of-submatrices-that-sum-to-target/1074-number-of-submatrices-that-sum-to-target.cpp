class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector <vector <int>> prefix(n,vector <int>(m));
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                if(j == 0) prefix[i][j] = matrix[i][j];
                else prefix[i][j] = prefix[i][j-1] + matrix[i][j]; 
            }
        }
        for(int i = 0; i <m; i++){
            for(int j = i; j <m; j++){
                unordered_map <int,int> count;
                count[0] = 1;
                int cur_sum = 0;
                for(int k = 0; k <n; k++){
                    cur_sum += prefix[k][j];
                    if(i > 0) cur_sum -= prefix[k][i-1];
                    ans += count[cur_sum - target];
                    count[cur_sum]++;
                }
                
            }
        }
        return ans;
    }
};
// subarray sum equals to k
// 0 1 1
// 1 2 3
// 0 1 1