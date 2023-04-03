class Solution {
public:
    int dp[11][11][2];
    int solve(string &s, int idx,int cnt, bool flag){
        if(idx == s.size()){
            return cnt;
        }
        if(dp[idx][cnt][flag]!=-1) return dp[idx][cnt][flag];
        char ub = '9';
        if(flag) ub = s[idx];
        int count = 0;
        for(char x = '0'; x <= ub; x++){
            bool new_flag = flag & (x == ub);
            int new_cnt = cnt;
            if(x == '1') new_cnt++;
            count += solve(s,idx+1,new_cnt,new_flag);
        }
        return dp[idx][cnt][flag] = count;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof dp);
        return solve(s,0,0,true);
    }
};

// I can applied digit dp here
// here n<= 1e9 so , string length will be atmost 10
// we can keep three states , string processed so far (idx) ,  if we have already taken less than the number