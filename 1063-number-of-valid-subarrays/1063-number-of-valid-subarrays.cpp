// Generated By Leetcode2IDE
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
    int validSubarrays(vector<int>& nums) {
        vector <int> m_stack;
        int count = 0;
        for(auto &x:nums) {
            while(m_stack.size() && m_stack.back() > x){
                m_stack.pop_back();
            }
            m_stack.push_back(x);
            count += m_stack.size();
        }
        return count;
    }
};
