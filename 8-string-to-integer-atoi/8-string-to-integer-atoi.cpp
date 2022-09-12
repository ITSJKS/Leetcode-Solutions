class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        int n = s.length();
        long long ans = 0;
        int j = 0;
        while(s[j] == ' ') j++;
        if(s[j]=='-'){
            neg = true;
            j++;
        }
        else if(s[j] == '+') j++;
        bool infinite = false;
            bool zeroes = true;
            bool started = false;
            for(int i = j;  i <n; i++){
                if(zeroes && (s[i] == '0')){
                    started  = true;
                    continue;
                }
                else if(s[i]>='0' && s[i] <='9'){
                    zeroes = false;
                    started = true;
                    int prev = ans;
                    ans =  ans*10 + (s[i]-'0');
                    if(ans > INT_MAX){
                        if(!neg)
                        ans = INT_MAX;
                        else{
                            ans = INT_MIN;
                        }
                        infinite = true;
                        break;
                    }
                    
                }
                else{
                    break;
                }
            }
        if(infinite) return ans;
        return neg?-ans:ans;
    }
};