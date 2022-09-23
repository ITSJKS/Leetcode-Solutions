class Solution {
    int mod = 1e9 + 7;
public:
    int no_of_bits(int n){
        return 32 - __builtin_clz(n);
    }
    
    int concatenatedBinary(int n) {
        long ans = 0;
        for(int i = 1; i <=n; i++){
            ans = i + (ans<<no_of_bits(i)%mod)%mod;
        }
        return ans;
    }
};