class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector <int> left(n);
        int l = -1e5;
        for(int i = 0; i <n; i++){
            if(seats[i]) l = i;
            else left[i] = i - l;
        }
        int right = 1e5;
        int ans = 0;
        for(int i = n-1;i>=0; i--){
            if(seats[i]) right = i;
            else ans = max(ans,min(left[i],right-i));
        }
        return ans;
    }
};

// distance between alex and closest person is maximized
// we r gonna keep distance between left and right for every space and return min(mini,max(left,right));