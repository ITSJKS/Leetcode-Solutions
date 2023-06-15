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
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        sort(all(jobs));
        sort(all(workers));
        int maxi = 0;
        for(int i = 0; i <workers.size(); i++){
            maxi = max(maxi,(jobs[i]+workers[i] - 1)/workers[i]);
        }
        return maxi;
    }
};