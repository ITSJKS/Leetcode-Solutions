class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int,int> start = {0,0};
        int d = 90;
        map <int,pair<int,int>> dir;
        dir[90] = {0,1};
        dir[0] = {1,0};
        dir[180] = {-1,0};
        dir[270] = {0,-1};
        int counter = 0;
       for(auto ch:instructions){
            if(ch == 'G'){
                start.first += dir[d].first;
                start.second += dir[d].second;
            }
            else if(ch == 'R'){
                d  = ((d-90)%360+360)%360;
            }
            else{
                d = (d + 90)%360;
            }
        }
        // cout<<start.first<<" "<<start.second<<" "<<d<<endl;
        if((start.first == 0 && start.second == 0) || d != 90) return true;
        return false;
    }
};