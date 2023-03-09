class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long long  n = edges.size();
        long long maxi= 0;
        vector <long long> ans(n,0);
        for(int i = 0; i <n; i++){
            ans[edges[i]]+=i;
            maxi = max(maxi,ans[edges[i]]);
        }
        int res = -1;
        for(int i = n-1; i>=0; i--){
            if(ans[i] == maxi){
                res = i;
            }
        }
        return res;
    }
};