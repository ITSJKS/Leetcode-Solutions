class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector <int> lps(n);
        lps[0] = 0;
        int len = 0, i = 1;
        while(i < n){
            if(s[i] == s[len]){
                lps[i] = ++len;
                i++;
            }
            else{
                if(len == 0){
                    lps[i] = len;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
        return s.substr(0,lps.back());
    }
};