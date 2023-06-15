class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int n  = s.size() , m = t.size();
        while(i < n && j < m){
            if(s[i] == t[j]) j++;
            i++;
        }
        if(j == m) return 0;
        return m-j;
    }
};