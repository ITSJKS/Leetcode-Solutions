class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector <int> g(n);
        for(auto x:roads){
            g[x[0]]++;
            g[x[1]]++;
        }
        long long count = 0;
        sort(g.begin(),g.end());
        int start = 1;
        for(auto x:g){
            count += x*1ll*start;
            start++;
        }
        return count;
    }
};