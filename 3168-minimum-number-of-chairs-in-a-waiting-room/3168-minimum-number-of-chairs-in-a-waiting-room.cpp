class Solution {
public:
    int minimumChairs(string s) {
        int maxi = 0;
        int cur = 0;
        for(auto &x:s){
            if(x == 'E') cur++;
            else cur--;
            maxi = max(maxi,cur);
        }
        return maxi;
    }
};