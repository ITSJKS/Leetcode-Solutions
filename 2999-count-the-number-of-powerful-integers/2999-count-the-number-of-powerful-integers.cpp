class Solution {
public:
    long long dp[16][2][2];
    long long solve(string &s, string &t,int idx, bool flag,bool suff,int limit){
        if(s.size()< t.size()) return 0ll;
        if(idx >= s.size()){
            return suff;
        }
        if(dp[idx][flag][suff]!=-1) return dp[idx][flag][suff];
        bool check = false;
        int start = s.size() - t.size();
        char ub = flag ? s[idx]  : limit+'0';
        long long count = 0;
        for(char x = '0'; x <= ub && x <=(limit+'0'); x++){
            bool new_flag = flag & (x == ub);
            bool sf = true;
            if(idx >= start && x != t[idx-start]) {
                sf = false;
            }
            count += solve(s,t,idx+1,new_flag,sf&suff,limit);
        }
        return dp[idx][flag][suff] = count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long val =stol(s);
        if(val > finish) return 0;
        start -= 1;
        string s1 = to_string(start);
        string s2 = to_string(finish);
        reverse(s1.begin(), s1.end());
        while(s1.size() < s2.size()) s1 += '0';
        reverse(s1.begin(), s1.end());
        memset(dp,-1,sizeof dp);
        long long val1 = solve(s1,s,0,1,1,limit);
        memset(dp,-1,sizeof dp);
        long long val2 = solve(s2,s,0,1,1,limit);
        return val2-val1;
    }
};