class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int cnt = 0;
        int mini = INT_MAX;
        for(auto x:matrix){
            for(auto y:x){
                if(y < 0) cnt++;
                mini = min(mini,abs(y));
                ans += abs(y);
            }
        }
        if(cnt%2 == 0) return ans;
        return ans - 2*mini;
    }
};