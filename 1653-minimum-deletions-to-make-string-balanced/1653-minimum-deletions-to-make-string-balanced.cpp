
#define fi       first
#define se       second
#define ll       long long
#define pb       push_back
#define pii      pair<int,int>
#define pll      pair<long long,long long>
#define vi       vector<int>
#define vl       vector<long long>
#define mii      map<int,int>
#define mll      map<long long,long long>
#define qi       queue<int>
#define pqb      priority_queue<int>
#define pqs      priority_queue<int,vi,greater<int> >
#define mod      1000000007
#define inf      INT_MAX
#define ninf      INT_MIN
#define ld       long double
#define f(i,x)     for(int i=0;i<(int)x;i++)
#define rep(i,a,b)   for(int i=(int)a;i<=(int)b;i++)   
#define endl      '\n'
#define all(arr)    arr.begin(),arr.end()


class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector <pii> v(n);
        int cnt_b = 0, cnt_a = 0;
        for(int i = 0; i <n; i++){
            v[i].fi = cnt_b;
            v[n-i-1].se = cnt_a;
            if(s[i] == 'b') cnt_b++;
            if(s[n-i-1]=='a') cnt_a++;
        }
        int ans = 1e6;
        for(int i = 0; i <n; i++){
            ans = min(ans,v[i].fi + v[i].se);
        }
        return ans;
    }
};
