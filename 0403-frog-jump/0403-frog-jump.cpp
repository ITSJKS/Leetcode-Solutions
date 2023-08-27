class Solution {
public:
    int dp[2001][2001];
    bool solve(int ind, int prev, vector <int>&stones,unordered_map <int,int>&mp){
        if(ind == stones.size() - 1) return true;
        // previous k 
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        int k = stones[ind] - stones[prev];
        bool check = false;
        if(mp.count(stones[ind] + k)) check |= solve(mp[stones[ind]+k],ind,stones,mp);
        if(mp.count(stones[ind] + k - 1) && mp[stones[ind]+k - 1] > ind) check |= solve(mp[stones[ind]+k-1],ind,stones,mp);
        if(mp.count(stones[ind] + k + 1)) check |= solve(mp[stones[ind]+k+1],ind,stones,mp);           
        return dp[ind][prev] = check;
}
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        memset(dp,-1,sizeof dp);
        unordered_map <int,int> mp;
        for(int i = 0; i <stones.size(); i++){
            mp[stones[i]] = i;
        }
        return solve(1,0,stones,mp);
    }
};

// first jump must be 1 unit
// so second stones should be 1