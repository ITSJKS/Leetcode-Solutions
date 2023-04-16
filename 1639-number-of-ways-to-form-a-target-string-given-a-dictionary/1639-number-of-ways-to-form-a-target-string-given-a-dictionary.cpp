class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int idx1, int idx2,vector <string> &words,string &target,vector <vector <int>> &dp,vector <vector <int>> &freq){
        if(idx1 == words[0].size()){
            if(idx2 == target.size()) return 1;
            else return 0;
        }
        if(idx2 == target.size()) return 1;
        // take it
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        long long count = 0;
        char ch = target[idx2];
        count = (freq[idx1][ch-'a']*(long long)solve(idx1+1,idx2+1,words,target,dp,freq))%mod;
        count =(count + solve(idx1+1,idx2,words,target,dp,freq))%mod;
        // not take it
        return dp[idx1][idx2] = count;
    }
    int numWays(vector<string>& words, string target) {
        int n =target.size();
        int m = words[0].size();
        vector <vector <int>> dp(m,vector <int>(n,-1));
        vector <vector <int>> freq(m,vector <int>(26,0));
        for(int i = 0; i < m; i++){
            for(int j = 0;j <words.size(); j++){
                char ch = words[j][i];
                freq[i][ch-'a']++;
            }
        }
        return solve(0,0,words,target,dp,freq);
    }
};