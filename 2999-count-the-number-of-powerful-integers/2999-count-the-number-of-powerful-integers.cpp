class Solution {
public:
    long long dp[16][2];
    long long solve(string &s, string &t,int idx, bool flag,int limit){
        if(s.size()< t.size()) return 0ll;
        if(idx >= s.size()){
            return 1ll;
        }
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        bool check = false;
        int start = s.size() - t.size();
        char ub = limit+'0';
        if(flag) ub = s[idx];
        long long count = 0;
        for(char x = '0'; x <= ub && x <= (limit+'0'); x++){
            bool new_flag = flag & (x == ub);
            if(idx>= start){
                if(x == t[idx-start]) count += solve(s,t,idx+1,new_flag,limit);
            }
            else{
                count += solve(s,t,idx+1,new_flag,limit);
            }
        }
        return dp[idx][flag] = count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long val =stol(s);
        if(val > finish) return 0;
        start -= 1;
        string s1 = to_string(start);
        string s2 = to_string(finish);
        memset(dp,-1,sizeof dp);
        long long val1 = solve(s1,s,0,1,limit);
        memset(dp,-1,sizeof dp);
        long long val2 = solve(s2,s,0,1,limit);
        return val2-val1;
    }
};