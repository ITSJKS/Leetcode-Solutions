class Solution {
public:
    vector <int> dp;
    int solve(int pos){
        if(dp[pos]>0) return dp[pos];
        int bit = ceil(log2(pos+1));
        if(pos == (1<<bit)-1) return dp[pos] = bit;
        dp[pos] = bit + 1 + solve(pow(2,bit)-1-pos);
        for(int m = 0; m < bit-1; m++){
            int cur = pow(2,bit-1)-pow(2,m);
            dp[pos] = min(dp[pos],bit + m + 1 + solve(pos-cur));
        }
        return dp[pos];
    }
    int racecar(int target) {
        dp.resize(target+1,0);
        return solve(target);
        
    }
};

/*
pos -> 0 and speed +1 on an infinite number line.

'A':
position += speed;
speed*=2;

'R':
if(speed <0) speed = -1
else speed = 1

shortest sequence of instruction to reach target

     A    A    A    R    A
0 -> 1 -> 3 -> 7 -> 7 -> 6

 0 - > 1  - > 3 - > 7  - > 6

*/