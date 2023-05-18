class Solution {
public:
    int dp[16385][16];
    int solve(int state,int cur, vector <int> &tasks, int sT){
        int n = tasks.size();
        int last_state = (1<<n) -1 ;
        if(state == last_state) return 0;
        if(dp[state][cur]!=-1) return dp[state][cur];
        int ans = 1e8;
        for(int i = 0; i <n; i++){
            if((state>>i)&1) continue;
            int new_state = state | (1<<i);
            if(cur >= tasks[i]) {
                ans = min(ans,solve(new_state,cur - tasks[i],tasks,sT));
            }
            else{
                ans = min(ans, 1 + solve(new_state,sT - tasks[i],tasks,sT));
            }
        }
        return dp[state][cur] = ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        memset(dp,-1,sizeof dp);
        return 1 + solve(0,sessionTime,tasks,sessionTime);
    }
};

// we can represent the state of tasks done by a 14 bit array which will contain the state of each index