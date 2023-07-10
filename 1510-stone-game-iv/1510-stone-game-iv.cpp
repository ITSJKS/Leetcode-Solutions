class Solution {
public:
    int dp[100001];
    bool solve(int num,vector <int> &v){
        if(dp[num]!=-1) return dp[num];
        bool check = false;
        for(auto &x:v){
            if(num < x) break;
            check |= solve(num-x,v)==0;
        }
        return dp[num] = check;
    }
    bool winnerSquareGame(int n) {
        vector <int> v;
        for(int i = 1; i*i <=n; i++){
            v.push_back(i*i);
        }
        memset(dp,-1,sizeof dp);
        return solve(n,v);
    }
};