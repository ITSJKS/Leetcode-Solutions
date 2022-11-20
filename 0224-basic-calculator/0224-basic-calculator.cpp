class Solution {
public:
    int calculate(string s) {
    stack<int> val, sig;
    long long num=0,res=0,sign=1;
    
    if(s=="")
        return 0;
    for(auto c:s) {
        if(isdigit(c)) {
             num = (num * 10) + c - '0';
        }
        else {
            res+=(int)sign*num;
            num=0;
            if(c=='+') sign=1;
            if(c=='-') sign=-1;
            if(c=='(') {
                val.push(res);
                sig.push(sign);
                res=0;
                sign=1;
            }
            if(c==')' and val.size()) {
                res=res*sig.top()+val.top();
                val.pop();
                sig.pop();
            }
            
        }
        
    }
    res+=(int)sign*num; //last digit
    return res;

    }
};