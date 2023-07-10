class Solution {
public:
    int dp[51];
    int maxA(int n) {
        if(n <=3) return n;
        if(dp[n]) return dp[n];
        int maxi = n;
        for(int i =3; i<=n; i++){
            maxi = max(maxi,maxA(n-i)*(i-1));
        }
        return maxi;
    }
};
// if we click ctrl A then it is not okay to again press A as we could have done that in last term and then pressed A 
// so whenever we do A we are gonna subtract n - 3 and add the current size