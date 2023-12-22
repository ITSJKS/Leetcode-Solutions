class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        for(auto &x:s) ones += x=='1';
        int zeroes = s[0] == '0';
        ones -= !zeroes;
        int ans = 0;
        for(int i = 1; i<s.size(); i++){
            ans=  max(ans,zeroes + ones);
            ones -= s[i] == '1';
            zeroes += s[i] == '0';
        }
        return ans;
    }
};