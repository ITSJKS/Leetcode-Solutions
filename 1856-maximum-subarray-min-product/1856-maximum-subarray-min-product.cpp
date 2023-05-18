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
    vector <ll> solve(vector <int> &v, bool check){
        vector <int> nums(v.begin(),v.end());
        if(check) reverse(nums.begin() , nums.end());
        int n = nums.size();
        vector <ll> ans(n);
        stack <int> st;
        for(int i = 0; i <n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(st.empty()) ans[i] = 0;
            else ans[i] = st.top() + 1;
            st.push(i);
        }
        if(check){
            reverse(ans.begin(),ans.end());
            for(int i = 0; i <n; i++){
            ans[i] = n-1 - ans[i];
        }
        }
        return ans;
    }
    int maxSumMinProduct(vector<int>& nums) {
        vector <ll> left = solve(nums,0);
        vector <ll> right = solve(nums,1);
        // for(auto &x:left) cout<<x<<" ";
        // cout<<endl;
        // for(auto &x:right) cout<<x<<" ";
        // cout<<endl;
        int n = nums.size();
        vector <ll> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i <n; i++){
            prefix[i] += prefix[i-1] +nums[i];
        }
        ll ans = 0;
        for(int i = 0; i <n; i++){
            int r = right[i];
            int l = left[i];
            ll sum = prefix[r];
            if(l >= 1) sum -= prefix[l-1];
            // cout<<l<<" "<<r<<endl;
            // cout<<sum<<" ";
            // cout<<prefix[i]<<" ";
            ans = max(ans,sum*1ll*nums[i]);
        }
        ans = ans%mod;
        return ans;
    }
};