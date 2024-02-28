class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [&](vector <int>&a, vector <int>&b){
            if(a[1] == b[1] ) return a[0] < b[0];
            return a[1] < b[1];
        };
        sort(points.begin(),points.end(),cmp);
        int count = 0;
        long long cur = -1e10;
        for(auto &x:points){
            if(x[0] > cur){
                count++;
                cur = x[1];
            }
        }
        return count;
    }
};