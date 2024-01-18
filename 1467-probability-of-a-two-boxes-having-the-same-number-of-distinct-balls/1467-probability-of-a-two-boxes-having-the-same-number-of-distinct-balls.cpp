class Solution {
public:
    double dp[8][25][9][9];
    double fact(int num){
        double fact = 1;
        for(int i = 1; i<=num; i++){
            fact = fact*i;
        }
        return fact;
    }
    double solve(int ind, vector <int>&balls,int total, int cur1,int mask1, int mask2){
        if(2*cur1 > total) return 0;
        if(ind == balls.size()){
            if(2*cur1 == total && mask1 == mask2) return fact(total/2)*fact(total/2);
            return 0;
        }
        if(dp[ind][cur1][mask1][mask2]>= 0) return dp[ind][cur1][mask1][mask2];
        double ans = 0;
        for(int i = 0; i <= balls[ind]; i++){
            int rem = balls[ind]-i;
            ans += solve(ind+1,balls,total,cur1+i,mask1 + (i!=0),mask2 + (rem!=0))/(1.0*fact(i)*fact(rem));
        }
        return dp[ind][cur1][mask1][mask2] = ans;
    }
    double getProbability(vector<int>& balls) {
        int total = accumulate(balls.begin(),balls.end(),0);
        double fact1 = fact(total);
        for(auto &x:balls){
            fact1/=fact(x);
        }
        memset(dp,-1,sizeof dp);
        double val2 = solve(0,balls,total,0,0,0);
        return val2/fact1;
    }
};