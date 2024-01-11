#define ll long long
vector <ll> fact;
ll mod = 1e9 + 7;
vector <ll> pow2;
const int N = 1e5 + 1;
bool check = true;
void init(){
    fact.resize(N);
    pow2.resize(N);
    fact[0] = 1ll;
    pow2[0] = 1;
    for(int i = 1; i <N; i++){
        fact[i] = (fact[i-1]*1ll*(i))%mod;
        pow2[i] = (pow2[i-1]*1ll*2)%mod;
    }
    check = false;
}
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
class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        if(check){
            init();
        }
        sick.push_back(n);
        vector <int> lens;
        ll ans = 1;
        int total = 0;
        int prev = -1;
        for(auto &x:sick){
            int len = x-prev-1;
            if(len > 0){
                lens.push_back(len);
                total += len;
                if(prev > -1 && x < n){
                    ans = (ans*1ll*pow2[len-1])%mod;
                }
            }
            prev = x;
        }
        ans =(ans*fact[total])%mod;
        for(auto &x:lens){
            ans = ans*1ll*binpow(fact[x],mod-2,mod)%mod;
        }
        return ans;
    }
};

// there are n child 
// k child are sick
// we need to find a sequence of n - k which will be followed by sick childs
// suppose the child are like this

// sick . . . . sick . . . sick sick sick . . . sick
// after one second 