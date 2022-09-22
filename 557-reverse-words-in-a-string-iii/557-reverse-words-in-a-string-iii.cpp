class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        while(i<n){
            if(s[i] == ' '){
                reverse(s.begin()+i-j,s.begin()+i);
                j = 0;
            }
            else{
                j++;
            }
            i++;
        }
        reverse(s.begin()+i-j,s.begin()+i);
        return s;
    }
};