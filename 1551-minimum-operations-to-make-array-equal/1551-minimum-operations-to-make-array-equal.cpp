class Solution {
public:
    int term(int a, int d, int n){
        return a + (n-1)*d;
    }
    int minOperations(int n) {
        int a = 1,d = 2;
        if(n%2){
            int mid = term(a,d,(n/2)+1);
            int sum = (n/2+1)*(1 + mid)/2;
            return (n/2 +1)*mid - sum;
        }
        int mid1 = term(a,d,(n/2));
        int mid2 = term(a,d,(n/2+1));
        int sum = (1 +  mid1)*(n/2)/2;
        int mid = (mid1+mid2)/2;
        return n/2*mid - sum;
    }
};