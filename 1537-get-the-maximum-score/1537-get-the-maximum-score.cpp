class Solution {
public:
    vector <vector <long long>> dp;
    int cnt = 0;
    long long solve(int ind, int turn, unordered_set <int> &st1, unordered_set <int>&st2,unordered_map <int,int>&rev){
        if(ind > cnt) return 0;
        if(dp[ind][turn]!=-1) return dp[ind][turn];
        long long ans = 0;
        if(turn == 0 && st1.count(ind)){
            ans = max(ans,rev[ind]*1ll + solve(ind+1,turn,st1,st2,rev));
        }
        else{
            ans = max(ans,solve(ind+1,turn,st1,st2,rev));
        }
        if(turn == 1 && st2.count(ind)){
            ans = max(ans,rev[ind]+solve(ind+1,turn,st1,st2,rev));
        }
        else{
            ans = max(ans,solve(ind+1,turn,st1,st2,rev));
        }
        if(st1.count(ind) && st2.count(ind)){
            ans = max(ans,max(rev[ind]+solve(ind+1,0,st1,st2,rev),rev[ind]+solve(ind+1,1,st1,st2,rev)));
        }
        return dp[ind][turn] = ans;
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        map <int,int> mp;
        for(auto &x:nums1) mp[x];
        for(auto &x:nums2) mp[x];
        cnt = 0;
        unordered_map <int,int> rev;
        for(auto &x:mp){
            x.second = cnt;
            rev[cnt] = x.first;
            cnt++;
        }
        unordered_set <int> st1,st2;
        for(auto &x:nums1){
            x = mp[x];
            st1.insert(x);
        }
        for(auto &x:nums2){
            x = mp[x];
            st2.insert(x);
        }
        dp.resize(cnt+1,vector <long long>(2,-1));
        int mod = 1e9 + 7;
        return (max(solve(0,0,st1,st2,rev),solve(0,1,st1,st2,rev)))%mod;
    }
};
/*
I can do cordinate compression
then I will have at most 2*1e5 element
then we can apply dp on 



*/