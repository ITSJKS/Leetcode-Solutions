class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size();
        int m = t.size();
        int ans = 0;
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                int d = 0;
                for(int k = 0; k <min(n-i,m-j); k++){
                    if(s[k+i]!=t[k+j]) d++;
                    if(d>1) break;
                    ans += d;
                }
            }
        }
        return ans;
    }
};