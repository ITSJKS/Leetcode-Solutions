class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        string res  =s;
        reverse(s.begin(),s.end());
        res += "#";
        res += s;
        int n = res.size();
        vector  <int> lps(n,0);
        int len = 0, i = 1;
        while(i < n){
            if(res[i] == res[len]){
                lps[i] = ++len;
                i++;
            }
            else{
                if(len == 0){
                    lps[i] = 0;
                    i++;
                }
                else len = lps[len-1];
            }
        }
        int m = lps.back();
        int size = s.size();
        return s.substr(0,size-m) + t;
    }
};