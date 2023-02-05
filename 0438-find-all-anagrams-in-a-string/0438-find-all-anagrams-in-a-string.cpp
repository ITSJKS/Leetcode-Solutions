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
    vector<int> findAnagrams(string s, string p) {
        vi ans;
        if(p.size()>s.size()) return ans;
        int n = s.size();
        int m = p.size();
        vi freq1(26,0);
        vi freq2(26,0);
        for(int i = 0; i < p.size(); i++){
            freq1[s[i]-'a']++;
            freq2[p[i]-'a']++;
        }
        if(freq1 == freq2) ans.push_back(0);
        for(int i = m; i < n; i++){
            freq1[s[i-m]-'a']--;
            freq1[s[i]-'a']++;
            if(freq1 == freq2) ans.push_back(i-m+1);
        }
        return ans;
    }
};