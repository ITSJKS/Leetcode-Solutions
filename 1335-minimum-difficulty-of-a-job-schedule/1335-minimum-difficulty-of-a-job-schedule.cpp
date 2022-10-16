class Solution {
public:
    int dp[301][11];
    // states will be index(300)  and d(10) days left
    int minDifficulty(vector<int>& jd, int d) {
        memset(dp,-1,sizeof(dp));
        int r = find_ans(jd,0,d);
        if(r >= INT_MAX) return -1;
        else return r;
    }
    int find_ans(vector <int> &jd, int idx, int d){
        int n = jd.size();
        if(idx  == n && d == 0){
            return 0;
        }
        if(d == 0) return 3000000;
        if(dp[idx][d]!=-1) return dp[idx][d];
        int cost = INT_MIN,best = INT_MAX;
        for(int i = idx; i+d<=n; i++){
            cost = max(cost,jd[i]);
            best = min(best,cost + find_ans(jd,i+1,d-1));
        }
        return dp[idx][d] = best;
    }
};