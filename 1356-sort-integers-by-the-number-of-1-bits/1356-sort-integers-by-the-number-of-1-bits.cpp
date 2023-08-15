class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto cmp = [&](int a, int b){
        int cnt1 = __builtin_popcount(a);
        int cnt2 = __builtin_popcount(b);
            if(cnt1 == cnt2) return a < b;
            return cnt1 < cnt2;
        };
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};