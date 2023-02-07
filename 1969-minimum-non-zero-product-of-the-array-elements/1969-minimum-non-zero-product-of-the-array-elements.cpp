class Solution {
public:
    long long mod = 1e9 + 7;
    long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
    }
    int minNonZeroProduct(int p) {
        long long range = ((1ll<<p)-1);
        return (long long)(binpow(range-1,range/2,mod)%mod*(range%mod))%mod;
    }
};