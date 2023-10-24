class Solution {
public:
    int dp[501][501];
    int solve(int start, int end, vector <int> &stones,vector <int>&prefix){
        if(start >= end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans = 0;
        for(int i = start; i<end; i++){
            int left = prefix[i];
            if(start > 0) left -= prefix[start-1];
            int right = prefix[end] - prefix[i];
            if(left >= right) ans = max(ans,right + solve(i+1,end,stones,prefix));
            if(right >= left) ans = max(ans, left + solve(start,i,stones,prefix));
        }
        return dp[start][end] = ans;
    }
    int stoneGameV(vector<int>& stones) {
        int n = stones.size();
        vector <int> prefix(n);
        memset(dp,-1,sizeof dp);
        prefix[0] = stones[0];
        for(int i = 1; i <n; i++){
            prefix[i] = prefix[i-1] + stones[i];
        }
        return solve(0,n-1,stones,prefix);
    }
};

/*
several stones arranged in a row
each stone has an associated value which is an integer given in the array stoneValue
maximum score that alice can obtain

in each round, alice divides the row into two non empty rows
, bob calculates the value of each row, bob throw aways the row which has maximum value and alice score += rem_row_value
 game end when there is only one stone remaining

stones length is 500

number of times it will go on
1 2 3 4 5 15


*/