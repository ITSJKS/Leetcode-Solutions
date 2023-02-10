class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        if(len == 0) return 0;
        long long last_num = 0, cur_num = 0;
        int res = 0;
        char cur_op = '+';
        for(int i =0; i<len; i++){
            char cur_char = s[i];
            if(isdigit(cur_char)){
                cur_num = (cur_num*10) + (cur_char - '0');
            }
            if(!isdigit(cur_char) && cur_char != ' ' || i == len - 1){
                if(cur_op == '+' || cur_op == '-'){
                    res += last_num;
                    last_num = (cur_op == '+')?cur_num:-cur_num;
                }
                else if(cur_op == '*'){
                        last_num*=cur_num;
                }
                else if(cur_op == '/'){
                    last_num/=cur_num;
                }
                cur_op = cur_char;
                cur_num = 0;
            }
        }
        res += last_num;
        return res;
    }
};