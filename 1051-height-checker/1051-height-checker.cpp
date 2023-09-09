class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector <int> v= heights;
        sort(v.begin(),v.end());
        int n  = v.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(heights[i]!=v[i]) cnt++;
        }
        return cnt;
    }
};