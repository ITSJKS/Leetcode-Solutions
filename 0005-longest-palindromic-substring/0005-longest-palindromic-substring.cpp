class Solution {
public:
    vector <vector <int>> dp;
    bool solve(int i, int j, string &s){
        if(i == j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;
        if(j - i == 1){
            ans =  s[i] == s[j];
        }
        else if(s[i] == s[j] && solve(i+1,j-1,s)){
            ans = true;
        }
        else{
            ans = false;
        }
        return dp[i][j] = ans;
    }
    // first approach
    // I am using dynamic programming to find if my given subarray is palindrome
    // 
    string longestPalindrome(string s) {
        int n = s.size();
        dp.resize(n+1,vector <int>(n+1,0));
        int max_len = 0;
        int start_idx = 0;
        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){
                int len = j - i + 1;
                if(len == 1) dp[i][j] = 1;
                else if(len == 2) dp[i][j] = s[i] == s[j];
                else{
                    dp[i][j] = (s[i] == s[j] ) && dp[i+1][j-1];
                }
                if(dp[i][j]){
                    if(j- i + 1> max_len){
                        max_len = j - i + 1;
                        start_idx = i;
                    }
                    
                }
            }
        }
        return s.substr(start_idx,max_len);
    }
    // Time complexity is O(n*n) as I am traversing each subarray and for these subarray I am checking if the current subarray is palindrome or not
    // I am using dynamic programming aproach to check if my current substring is palindrome
    
};

// Few more approach 
// we can use manacher algorithm also
// In that algorithm we 