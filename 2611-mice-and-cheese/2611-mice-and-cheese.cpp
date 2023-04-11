#define fi       first
#define se       second
#define ll       long long
#define pb       push_back
#define pii      pair<int,int>
#define pll      pair<long long,long long>
#define vpi       vector<pii>
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
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vpi v(n);
        for(int i = 0; i < n; i++){
            v[i] = {reward1[i]-reward2[i],i};
        }
        auto cmp = [&](pii p1,pii p2){
            return p1.first > p2.first;
        };
        sort(all(v),cmp);
        int ans = 0;
        for(int i = 0; i <n; i++){
            int idx = v[i].second;
            if(i < k){
                ans += reward1[idx];
            }
            else ans += reward2[idx];
        }
        return ans;
    }
};