class Solution {
public:
    int dp[102][102];
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return find_ans(s,0,k);
    }
    int find_ans(string &s, int idx, int k){
        if(dp[idx][k]!=-1) return dp[idx][k];
        if(idx == s.length() || s.size() - idx <= k ) return 0;
        
        map <char,int> count;
        int ans = INT_MAX;
        int most_freq = 0;
        for(int i = idx; i <s.length(); i++){
            char c = s[i];
            count[c]++;
            most_freq = max(most_freq,count[c]); // we want to keep these ones
            
            
            int compressed_length = 1 + (most_freq>1 ? to_string(most_freq).size() : 0);
            
            
            if(k>=(i-idx+1-most_freq))
             ans = min(ans,compressed_length + find_ans(s,i+1,k- (i-idx+1-most_freq)));
        }
        return dp[idx][k] = ans;
    }
    // we will keep two states first one will decide index, and second one will decide remaining deletion
    // as there are atmost k deletion we will always perform k deletion as k will always give shorter length than k - 1
};