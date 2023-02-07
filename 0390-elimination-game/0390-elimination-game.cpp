class Solution {
public:
    unordered_map <int,int> mp;
    int lastRemaining(int n) {
        if(n == 1) return 1;
        if(mp.find(n)!=mp.end()) return mp[n];
        return mp[n] = 2*(n/2-lastRemaining(n/2)+1);
    }
};