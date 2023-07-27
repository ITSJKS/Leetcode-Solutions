class Solution {
public:
    int dp[31][31];
    int solve(int i, int j, vector <int>&prefix,int k){
        if(i >= j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int cost = 1e9;
        for(int idx = i; idx <j; idx = idx + k-1){
            cost = min(cost,solve(i,idx,prefix,k) + solve(idx+1,j,prefix,k));
        }
        if((j-i)%(k-1) == 0) cost += prefix[j+1] - prefix[i];
        return dp[i][j] = cost;
    }
    int mergeStones(vector<int>& stones, int k) {
        memset(dp,-1,sizeof dp);
        int n = stones.size();
        if(n == 1) return 0;
        else if((n-1)%(k-1)!= 0) return -1;
        vector <int> prefix;
        int sum = 0;
        prefix.push_back(sum);
        for(auto &x:stones){
            sum += x;
            prefix.push_back(sum);
        }
        return solve(0,n-1,prefix,k);
    }
};

// merge exactly k piles into one
// In every move , I will decrease by k - 1 so ((n-1)%(k-1)) should be 0 , so I will have to perform (n-1)/k-1 moves in total
// I will have to choose these moves carefully


// If I am at index 0 and choose to 