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
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector <int> cords;
        for(auto &x:flowers){
            cords.push_back(x[0]);
            cords.push_back(x[1]+1);
        }
        for(auto &p:people){
            cords.push_back(p);
        }
        sort(all(cords));
        cords.resize(unique(all(cords))-cords.begin());
        map <int,int> mp;
        int start = 0;
        for(auto &x:cords){
            mp[x]  = start;
            start++;
        }
        vector <int> prefix(start,0);
        for(auto &x:flowers){
            prefix[mp[x[0]]]+=1;
            prefix[mp[x[1]+1]]-=1;
        }
        for(int i = 1; i<start; i++){
            prefix[i] += prefix[i-1];
        }
        vector <int> ans;
        for(auto &x:people){
            ans.push_back(prefix[mp[x]]);
        }
        return ans;
    }
};

// we can do cordinate compression and then take prefix sum to find number of flowers blooming when a person arrive
// to do this , we can 