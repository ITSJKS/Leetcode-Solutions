class Solution {
public:
    // we know that a point is inside a circle if we put the coordinate of the point in the circle equation we will get 
    bool check(int x, int y, vector <int> &circle){
        long long xc = circle[0] , yc = circle[1], r = circle[2];
        long long dx = abs(xc-x)*abs(xc-x);
        long long dy = abs(yc-y)*abs(yc-y);
        return dx + dy <= r*r;
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        int count = 0;
        for(int i = 0; i <=200; i++){
            for(int j =0; j <=200; j++){
                bool checked = true;
                for(int k = 0; k < circles.size() && checked; k++){
                    if(check(i,j,circles[k])){
                        count++;
                        checked = false;
                    }                
                }
            }
        }
        return count;
    }
};