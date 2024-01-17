class Solution {
public:
    vector <int> dp;
    int solve(int target,vector <int>& cost){
        if(target < 0) return -1e9;
        if(target == 0) return dp[target] = 0;
        if(dp[target]!=-1) return dp[target];
        int ans = -1e9;
        for(int j = 1; j <=9; j++){
            ans = max(ans, 1 + solve(target-cost[j-1],cost));
        }
        return dp[target] = ans;
    }
    string largestNumber(vector<int>& cost, int target) {
        dp.resize(target+1,-1);
        int len = solve(target,cost);
        if(len <= 0) return "0";
        string ans;
        for(int i = 8; i>=0; i--){
            while(target >= cost[i] && dp[target]==dp[target-cost[i]] + 1){
                ans.push_back(i + '1');
                target -= cost[i];
            }
        }
        return ans;
    }
};

// find the largest length then use that to form our answer
// we can use dp to find the longest length 
// then to get that length we need to use that dp table
// I don't know how the table looks so let's see