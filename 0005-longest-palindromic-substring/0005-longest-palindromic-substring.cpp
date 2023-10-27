class Solution {
public:
    string longestPalindrome(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return lc_substring(s,t);
    }
    string lc_substring(string s, string t){
        int n = s.length();
        int m = t.length();
        int dp[n+1][m+1];
        for(int i = 0; i <=n; i++){
            for(int j = 0; j <=m; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
            }
        }
        int res = 0;
        string str = "";
        for(int i =1; i <=n; i++){
            for(int j = 1; j <=m; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                     if(res<dp[i][j])
                    {
                        string temp=s.substr(i-dp[i][j],dp[i][j]);
                        string temp2=temp;
                        reverse(temp2.begin(), temp2.end());
                        if(temp==temp2) //we just want to check if matched substring is palindrome or not
                        {
                        res=dp[i][j];
                        str=temp;
                        }
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return str;
        // string maxi = "";
        // string temp = "";
        // int i = m,j = n;
        // while(i>0 && j>0){
        //     if(s[i-1]==t[j-1]){
        //         temp += s[i-1];
        //         string temp1 = temp;
        //         reverse(temp1.begin(),temp1.end());
        //         if(temp.size() >maxi.size() && temp == temp1){
        //             maxi = temp;
        //         }
        //         i--;
        //         j--;
        //     }
        //     else{
        //         temp = "";
        //         if(dp[i-1][j]>dp[i][j-1]){
        //             i--;
        //         }
        //         else{
        //             j--;
        //         }
        //     }
        // }
        // reverse(maxi.begin(),maxi.end());
        // return maxi;
    }
};