class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int n = c.size();
         int dx_ = c[1][0] - c[1-1][0];
         int dy_ = c[1][1] - c[1-1][1];
        for(int i =1 ; i <n; i++){
            int dx = c[i][0] - c[0][0];
            int dy = c[i][1] - c[0][1];
            if(dx_*dy!=dx*dy_) return false;
            
        }
        return true;
    }
};