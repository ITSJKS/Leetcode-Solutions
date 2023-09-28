class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        if(n <= 2) return "";
        vector <int> lps(n);
        int len = 0, i = 1;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
        int cnt = lps.back();
        return s.substr(0,cnt);
    }
};