class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int ind, int cur, vector <pair<int,int>>&v,vector <vector <int>> &dp){
        if(cur < 0) return 0;
        if(ind >= v.size()) return 1;
        if(dp[ind][cur]!=-1) return dp[ind][cur];
        int cnt = v[ind].second;
        int num = v[ind].first;
        long long count =  ((solve(ind+1,cur,v,dp) + solve(ind,cur-num,v,dp) - solve(ind+1,cur-(cnt+1)*num,v,dp))%mod+mod)%mod;
        return dp[ind][cur] = count;
    }
    int countSubMultisets(vector<int>& nums, int l, int r) {
        unordered_map <int,int> mp;
        for(auto &x:nums) mp[x]++;
        long long zero = mp[0]+1;
        mp.erase(0);
        vector <pair<int,int>> v;
        for(auto &x:mp) v.push_back(x);
        int n = mp.size();
        vector <vector <int>> dp(n,vector <int>(r+1,-1));
        int left = solve(0,l-1,v,dp);
        int right = solve(0,r,v,dp);
        return ((right - left+mod)%mod*1ll*zero)%mod;
    }
};

// v[i][sum] = v[i+1][sum] + v[i+1][sum - a] + v[i+1][sum - 2*a] + v[i+1][sum - 3*a] + .... v[i+1][sum - k*a]

// v[i][sum+a] = v[i+1][sum+a]  + v[i+1][sum] + v[i+1][sum-a]  + v[i+1][sum -(k-1)*a]

// v[i][sum+a] = v[i+1][sum+a] + v[i][sum] - v[i+1][sum - k*a]
// let sum + a == x
// v[i][x] = v[i+1][x]+ v[i][x-a] - v[i+1][sum - k*a]

// that will be our recurrence for this problem
