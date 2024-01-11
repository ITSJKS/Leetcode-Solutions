class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        vector <vector <int>> parent(n,vector <int>(40));
        vector <vector <long long>> sum(n,vector <long long>(40,0ll));
        for(int i = 0; i <n; i++){
            parent[i][0] = receiver[i];
            sum[i][0] = receiver[i];
        }
        for(int j = 1; j <40; j++){
            for(int i = 0; i < n; i++){
                parent[i][j] = parent[parent[i][j-1]][j-1];
                sum[i][j] = sum[i][j-1] + sum[parent[i][j-1]][j-1];
            }
        }
        long long ans = 0;
        for(int i = 0; i <n; i++){
            long long cur_node = i;
            int pos = i;
            for(int j = 0; j <40; j++){
                if(k&(1ll<<j)){
                    cur_node += sum[pos][j];
                    pos = parent[pos][j];
                }
            }
            ans = max(ans,cur_node);
        }
        return ans;
    }
};

