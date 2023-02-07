class Solution {
public:
    bool isReachable(int tx, int ty) {
        while(tx>0 && tx%2 ==0) tx/=2;
        while(ty>0 && ty%2 ==0) ty/=2;
        if(__gcd(tx,ty) == 1) return true;
        return false;
    }
};