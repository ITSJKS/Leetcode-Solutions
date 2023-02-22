class Solution {
public:
    int countHousePlacements(int n) {
        long long x = 2;
        long long y = 3;
        if(n == 1) return 4;
        int mod = 1e9+7;
        for(int i = 3; i <=n; i++){
            long long z = (y+x)%mod;
            x = y;
            y = z;
        }
        return (y*y)%mod;
    }
};