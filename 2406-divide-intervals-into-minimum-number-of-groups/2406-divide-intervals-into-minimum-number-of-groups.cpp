class Solution {
public:
    const int N = 1e6 + 11;
    int minGroups(vector<vector<int>>& inv) {
        vector <int> count(N);
        for(auto x:inv){
            count[x[0]]++;
            count[x[1]+1]--;
        }
        int cur = 0, maxi = 0;
        for(auto x:count){
            cur += x;
            maxi = max(maxi,cur);
        }
        return maxi;
    }
};