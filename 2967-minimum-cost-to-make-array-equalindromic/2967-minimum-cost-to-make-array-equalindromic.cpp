bool check = true;
set <long long> v;
void solve(int ind, string &t, int len){
    int limit = len/2 -(len%2==0);
    if(ind > limit){
        long long num = stoll(t);
        if(num <= 1e9)
            v.insert(num);
        return;
    }
    int lb = 0;
    if(ind == 0) lb = 1;
    for(int i = lb; i<=9; i++){
        t[ind] = i+'0';
        t[len-ind-1] = i+'0';
        solve(ind+1,t,len);
    }
}
void find(){
    for(int i =1; i<=9; i++){
        string t(i,'.');
        solve(0,t,i);
    }
    check = false;
}
class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        if(check) find();
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector <long long> prefix(n,0ll);
        for(int i = 0; i <n; i++){
            if(i) prefix[i] = nums[i]*1ll + prefix[i-1];
            else prefix[i] = nums[i]*1ll;
        }
        long long ans = 1e16;
        int cnt = 0;
        for(auto &x:v){
            if(x > nums.back()) cnt++;
            if(cnt > 2) break;
            auto it = upper_bound(nums.begin(),nums.end(),x) - nums.begin();
            long long res = 0;
            if(it>0){
                res += (it)*1ll*x -  prefix[it-1];
            }
            res += ((prefix.back() - (it>0?prefix[it-1]:0ll)) - (n-it)*1ll*x);
            ans = min(ans,res);
        }
        // cout<<v.size();
        return ans;
    }
};