class Solution {
public:
    #define ll long long
    ll count(ll mid, ll a, ll b, ll c_){
        ll c = 0;
        c += mid/a;
        c+= mid/b;
        c += mid/c_;
        c -= mid/(lcm(a,b));
        c -= mid/(lcm(b,c_));
        c -= mid/(lcm(c_,a));
        c += mid/(lcm(lcm(a,b),c_));
        return c;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll l = 0, r = 1e11+1;
        while(r-l>1){
            ll mid = l + (r-l)/2;
            if(count(mid,a,b,c)>=n){
                r = mid;
            }
            else l = mid;
        }
        return r;
    }
};