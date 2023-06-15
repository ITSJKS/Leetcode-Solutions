
class Solution {
public:
    vector <int> prefix;
    int minMeetingRooms(vector<vector<int>>& inv) {
        prefix.resize(1e6+1,0);
        for(auto &x:inv){
            int u = x[0] , v = x[1];
            prefix[u]+=1;
            prefix[v]-= 1;
        }
        int maxi = 0;
        for(int i = 1; i <=1e6; i++){
            prefix[i] = prefix[i-1] + prefix[i];
            maxi = max(maxi,prefix[i]);
        }
        return maxi;
    }
};
// we can use something like a skyline for this
// every time meeting start we will do +1 on skyline and every time it end we will do -1 then find the maximum in the prefix sum;