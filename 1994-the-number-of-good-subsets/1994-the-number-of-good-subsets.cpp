#include <bits/stdc++.h>
using namespace std;
#define fi              first
#define se              second
#define ll              long long
#define pb              push_back
#define pii             pair<int,int>
#define pll             pair<long long,long long>
#define vi              vector<int>
#define vl              vector<long long>
#define mii             map<int,int>
#define mll             map<long long,long long>
#define qi              queue<int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define mod             1000000007
#define inf             INT_MAX
#define ninf            INT_MIN
#define linf            LLONG_MAX
#define lninf           LLONG_MIN
#define rep(i,a,b)      for(int i=(int)a;i<(int)b;i++)      
#define yes()           cout<<"YES"<<endl 
#define no()            cout<<"NO"<<endl
#define endl            '\n'
#define all(arr)        arr.begin(),arr.end()

// for debugging 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << (#x) << " is "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
void _print(int t) { cerr << t; }
void _print(ll t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


class Solution {
public:
    int m = 1e9 + 7;
    ll modpow(ll a, ll b){
        a %= m;
        ll res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % m;
            a=(a*1ll*a)%m;
            b>>=1;
        }
        return res;
    }
    // Did we really needed dp or my subset brute force could have passed
    int solve(int ind, vector <int> &v, int mask,vector <int> &freq){
        if(ind == v.size()) return mask > 0;
        // skip it and keep mask same as always
        ll no_take = (solve(ind+1,v,mask,freq))%m;
        ll take = 0;
        if((mask&v[ind]) == 0){
            take = ((solve(ind+1,v,mask|v[ind],freq)%m)*1ll*freq[v[ind]])%m;
        }
        return (take+no_take)%m;
        //take the current element
        
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        vector <int> primes = {2,3,5,7,11,13,17,19,23,29};
        vector <int> freq(1025,0);
        vector <int> v;
        int ones = 0;
        for(auto &x:nums){
            int num = x;
            int mask = 0;
            int bit = 0;
            if(num == 1){
                ones++;
                continue;
            }
            bool flag = false;
            for(auto p:primes){
                int cnt = 0;
                while(num%p == 0){
                    num/=p;
                    cnt++;
                    if(cnt > 1) break;
                }
                if(cnt > 1){
                    flag = true;
                    break;
                }
                if(cnt == 1) mask |= (1<<bit);
                bit++;
            }
            if(flag) continue;
            if(mask == 0) continue;
            freq[mask]++;
            if(freq[mask] == 1) v.push_back(mask);
        }
        // debug(v);
        // debug(freq);
        int pow_one = modpow(2,ones);
        int res = solve(0,v,0,freq);
        ll val = ((pow_one)%m*1ll*(res)%m)%m;
        return val;
    }
};
