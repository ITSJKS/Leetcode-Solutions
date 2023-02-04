class Solution {
public:
    bool checkString(string s) {
        int count_a =0;
        int n = s.size();
        for(int i = n-1; i >=0; i--){
            if(s[i] == 'b' && count_a) return false;
            if(s[i] == 'a') count_a++;
        }
        return true;
    }
};