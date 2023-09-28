class Solution {
public:
    pair<int,int> dp[101][101];
    int mod = 1e9 + 7;
    pair<int,int> solve(int i, int j, vector <string>&board){
        if(i <0 || j < 0) return {-1e9,0};
        if(i == 0 && j == 0) return {0,1};
        if(board[i][j]=='X') return {-1e9,0};
        if(dp[i][j].first != -1) return dp[i][j];
        pair<int,int> ans = {-1e9,0};
        if(board[i][j] == 'S') board[i][j] = '0';
        int cur = board[i][j]-'0';
        auto cur1 = solve(i-1,j-1,board);
        auto cur2 = solve(i,j-1,board);
        auto cur3 = solve(i-1,j,board);
        int maxi = max(cur1.first,max(cur2.first,cur3.first));
        if(maxi == -1e9) return dp[i][j] = ans;
        int cnt = 0;
        if(cur1.first == maxi) cnt = (cnt + cur1.second)%mod;
        if(cur2.first == maxi) cnt = (cnt + cur2.second)%mod;
        if(cur3.first == maxi) cnt = (cnt  + cur3.second)%mod;
        ans.first = maxi + cur;
        ans.second = cnt;
        return dp[i][j] = ans;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i<100; i++){
            for(int j = 0; j <100; j++) dp[i][j] = {-1,0};
        }
        auto ans = solve(n-1,m-1,board);
        if(ans.first < 0) ans = {0,0};
        return {ans.first,ans.second};
    }
};

/*
Number of path with maxScore
100*100*9
9*10^4
we can use the fact that we can go only up , left and up-left
i,j
i-1,j
i,j-1
i-1,j-1
so after k moves if we have
*/
