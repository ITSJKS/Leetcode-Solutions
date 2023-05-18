class Solution {
public:
    int countOrders(int n) {
        long long mod = 1e9 +7;
        long long ans = 1;
        for(int i = 2; i <=2*n; i++){
            ans = (ans*1ll*i);
            if(i%2 == 0) ans/=2;
            ans = ans%mod;
        }
        return ans;
    }
};