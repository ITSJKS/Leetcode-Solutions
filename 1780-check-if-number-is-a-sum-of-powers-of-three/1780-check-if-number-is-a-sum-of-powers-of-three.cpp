class Solution {
public:
    int solve(int n, int cur_sum,int power){
        if(cur_sum == n) return true;
        if(cur_sum > n) return false;
        for(int i = power; i <=16; i++){
            cur_sum += pow(3,i);
            if(solve(n,cur_sum,i+1)) return true;
            cur_sum -= pow(3,i);
        }
        return false;
    }
    bool checkPowersOfThree(int n) {
        return solve(n,0,0);
    }
};