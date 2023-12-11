class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map <int,int> mp;
        int n = arr.size();
        for(auto &x:arr){
            mp[x]++;
            if(4*mp[x] > n) return x;
        }
        return -1;
    }
};