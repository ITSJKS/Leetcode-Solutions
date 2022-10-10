class Solution {
public:
    string breakPalindrome(string &p) {
        if(p.size() == 1) return "";
        int n = p.size();
        string x = p;
        for(int i = 0; i<n/2; i++){
            if(p[i] == 'a') continue;
            else{
                p[i] = 'a';
                return p;
                
            }
        }
        p[n-1] = 'b';
        return p;
    }
};