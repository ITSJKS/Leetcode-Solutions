class Solution {
public:
    long long mod=  1e9 + 7;
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
    int maxNiceDivisors(int pf) {
        long long ans =  (pf-2)/3;
        pf = pf - ans*3;
        long long rem = 0;
        if(pf == 4) rem = 2;
        else if(pf == 3) ans += 1;
        else if(pf == 2) rem = 1;
        return (binpow(2,rem,mod)*1ll*binpow(3,ans,mod))%mod;
    }
};
/*
We are given positive integer primeFactors 
we are asked to construct a positive integer n that satisfies the given conditions

number of prime factors of n is at most primeFactors
question is turning out to be 
x1 + x2  = n


*/