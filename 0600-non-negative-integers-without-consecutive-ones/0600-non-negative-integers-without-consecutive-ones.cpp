class Solution {
public:
    int dp[32][2][2];
    int solve(int ind, bool flag, int cnt,string &s){
        if(cnt > 1) return 0;
        if(ind == s.size()) return 1;
        if(dp[ind][flag][cnt]!=-1) return dp[ind][flag][cnt];
        int ub = flag?s[ind]:'1';
        int count = 0;
        for(char ch = '0'; ch <= ub; ch++){
            bool f = flag;
            if(ch < ub) f = false;
            int c1 = cnt;
            if(ch == '1') c1++;
            else c1 = 0;
            count += solve(ind+1,f,c1,s);
        }
        return dp[ind][flag][cnt] = count;
    }
    int findIntegers(int n) {
        memset(dp,-1,sizeof dp);
        string s = bitset<31>(n).to_string();
        int idx = __builtin_clz(n);
        s = s.substr(idx-1);
        return solve(0,true,0,s);
    }
};
/*
I can use pnc here
I need to find number of integers in the range [0,n] whose binary representation do not contain consecutive zeroes

Can I use digit dp here
I need to fill each places such that 
I need to take care of previous value I am putting which would be 


*/