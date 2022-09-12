class Solution {
public:
    int convert_to_num(string num){
        int ans = 0;
        for(auto x:num){
            ans = ans*10 + (x-'0');
        }
        return ans;
    }
    int maximum69Number (int num) {
        string num1 = to_string(num);
        for(auto &x:num1){
            if(x == '6'){
                x = '9';
                break;
            } 
        }
        return convert_to_num(num1);
        
    }
};