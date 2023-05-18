class Solution {
public:
    int dp[12] = {};
    int maxi = 0;
    int solve(int ind , int cur, vector <int> &jobs, int k){
        if(cur >= maxi) return maxi;
        if(ind == jobs.size()) return maxi = cur;
        unordered_set <int> st;
        for(int w = 0; w <k; w++){
            if(st.count(dp[w])) continue;
            st.insert(dp[w]);
            dp[w] += jobs[ind];
            solve(ind+1,max(cur,dp[w]),jobs,k);
            dp[w] -= jobs[ind];
        }
        return maxi;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        if(k == jobs.size()) return *max_element(jobs.begin(),jobs.end());
        for(auto &x:jobs){
            maxi += x;
        }
        sort(jobs.begin(),jobs.end(), greater<int>());
        return solve(0,0,jobs,k);
    }
};