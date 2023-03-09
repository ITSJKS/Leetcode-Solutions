class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int ans = 0;
        int zeroes = 0;
        int n = s.size();
        for(int i  =0; i <n; i++){
            zeroes += s[i]=='0';
            if(s[i] == '1' && zeroes){
                ans = max(ans+1,zeroes);
            }
        }
        return ans;
    }
};