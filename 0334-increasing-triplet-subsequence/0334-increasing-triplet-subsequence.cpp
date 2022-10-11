class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // we are just checking for any two smaller numbers 
        int first = INT_MAX,second = INT_MAX;
        for(auto x:nums){
            if(x<=first) first = x;
            else if(x<=second) second = x;
            else return true;
        }
        return false;
    }
};