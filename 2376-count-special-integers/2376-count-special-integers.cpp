class Solution {
public:
    int dp[11][2][1025];
    int solve(int ind, bool tight, int mask , string &s){
        if(ind == s.size()) return mask != 0;
        if(dp[ind][tight][mask]!=-1) return dp[ind][tight][mask];
        int count = 0;
        int ub = tight?(s[ind]-'0'):9;
        for(int i = 0; i<=ub; i++){
            if(mask&(1<<i)) continue;
            int newMask = (mask == 0 && i == 0 ? mask : (mask | (1 << i)));
            int nextTight = (tight && i == (s[ind] - '0')) ? 1 : 0;
            count += solve(ind+1,nextTight,newMask,s);
        }
        return dp[ind][tight][mask] = count;
    }
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof dp);
        return solve(0,1,0,s);
    }
};
// let's assume we have 10 bits
// if 0th bit is set , 0 already taken
// if 1st bit is set , 1 already taken 
// if 2st bit is set ,

// number of special integers that belong to the interval [1,n]
// two digit 