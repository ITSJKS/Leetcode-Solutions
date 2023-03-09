class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
        long long count = 0;
        int prev = s[0];
        int cnt = 0;
        int ones = (s[0] == '1');
        for(int i = 1; i <n; i++){
            ones += (s[i] == '1');
            if(s[i]==s[i-1] && s[i] == '1'){
                cnt++;
                count = (count + cnt)%mod;
            }
            else{
                cnt = 0;
            }
        }
        return (count + ones)%mod;
    }
};