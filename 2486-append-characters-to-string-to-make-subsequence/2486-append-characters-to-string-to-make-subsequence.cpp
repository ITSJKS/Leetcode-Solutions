class Solution {
public:
    int appendCharacters(string s, string t) {
        int l1 = 0;
        int l2 = 0;
        int n = s.size(),m =t.size();
        while(l1 < n && l2 < m){
            if(s[l1] == t[l2]){
                l2++;
            }
            l1++;
        }
        return m - l2;
    }
};