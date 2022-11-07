class Solution {
public:
    int maximum69Number (int num) {
        string num1 = to_string(num);
        for(auto &x:num1){
            if(x == '6'){
                x = '9';
                break;
            } 
        }
        return stoi(num1);
        
    }
};