class Solution {
public:
    unordered_map <long long,int> mp;
    int solve(vector <int>&cnt, int prev, int m){
        long long mask = 0;
        for(int i =1 ; i <m; i++){
            mask = mask*1ll*31 + cnt[i];
        }
        mask = mask*1ll*31 + prev;
        if(mp.count(mask)) return mp[mask];
        int ans = 0;
        for(int i = 1; i <m; i++){
            if(cnt[i]){
                cnt[i]--;
                ans = max(ans,(prev == 0) + solve(cnt,(prev+i)%m,m));
                cnt[i]++;
            }
        }
        return mp[mask] = ans;
    }
    int maxHappyGroups(int m, vector<int>& groups) {
        vector  <int> cnt(m) ;
        int count = 0;
        for(auto &x:groups){
            if(x%m == 0) count++;
            else cnt[x%m]++;
        }
        return count + solve(cnt,0,m);
    }
};
/*
Few approach
we can do this thing
batchsize is 9
group size is 30

we need to make sum divisible by batchsize by taking these numbers
we need to make maximum number of partitions we can split the groups into such that the sum of group size in each partition is 0 mod batchsize.
at most one partition is allowed to have a different remainder the first group will get fresh donut anyway

dp state dp[freq][r] maximum number of partitions you can form given the current freq and current remainder
we can hash the freq array to store it in dp table

for each i from 0 to bs-1 
dp[freq][(r+i)%batchsize] we will take largest of all the next states and store it in ans
if(r == 0) return ans + 1 otherwise return ans
*/