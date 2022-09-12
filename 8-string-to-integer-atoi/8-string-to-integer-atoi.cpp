class Solution {
public:
    bool isValid(char c){
        return c>='0' && c<='9'; 
    }
    int myAtoi(string s) {
       int i = 0;
        bool neg = false;
       while(s[i]==' ') i++;
        if(s[i] == '-'){
            neg = true;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        int ans = 0;
        while(isValid(s[i]) && i < s.length()){
        if(!neg){
                if(ans>INT_MAX/10 || (ans==INT_MAX/10 && s[i]-'0'>=7)){
                    return INT_MAX;
                }
            }else{
                if(ans>INT_MAX/10 || (ans==INT_MAX/10 && s[i]-'0'>=8)){
                    return INT_MIN;
                }
            }
            ans = ans*10 + (s[i]-'0');
            i++;
        }
        return neg?-ans:ans;
    }
};