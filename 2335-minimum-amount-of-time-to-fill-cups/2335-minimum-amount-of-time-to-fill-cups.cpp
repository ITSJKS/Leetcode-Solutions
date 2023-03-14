class Solution {
public:
    int fillCups(vector<int>& a) {
        int sum = accumulate(a.begin(),a.end(),0);
        int maxi = *max_element(a.begin(),a.end());
        return max(maxi,(sum+1)/2);
    }
};