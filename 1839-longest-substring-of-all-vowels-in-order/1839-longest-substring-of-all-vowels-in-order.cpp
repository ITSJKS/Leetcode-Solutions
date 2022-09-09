class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int maxi_len = 0;
        int n = word.size();
        int i = 0;
        while(i<n){
            int a = 0,e = 0,ic = 0,o = 0,u = 0;
            while(i<n && word[i]=='a'){
                a++;
                i++;
            }
            while(i<n&& word[i] == 'e'){
                i++;
                e++;
            }
            while(i<n&& word[i] == 'i'){
                i++;
                ic++;
            }
            while(i<n && word[i] == 'o'){
                o++;
                i++;
            }
            while(i<n && word[i] == 'u'){
                u++;
                i++;
            }
            if(a>0 && e>0 && ic > 0 && o>0 && u>0){
                maxi_len = max(maxi_len,a+e+ic+o+u);
            }
        }
        return maxi_len;
    }
};