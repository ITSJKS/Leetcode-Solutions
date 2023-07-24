class Solution {
public:
    double myPow(double x, int n) {
        if(n>=0) return calc(x,0ll+n);
        else{
            return (1.0/calc(x,0ll-n));
        }
    }
    double calc(double x, long long n){
        double ans = 1.0;
        if(n==0) return double(1.0);
        double val = myPow(x,n/2);
        if(n&1){
            ans  =  x*double(val*val);
        }
        else{
            ans =  double(val*val);
        }
        return ans;
    }
};