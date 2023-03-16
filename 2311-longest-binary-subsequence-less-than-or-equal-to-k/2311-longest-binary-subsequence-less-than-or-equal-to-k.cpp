class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        for(auto x:s) count += (x=='0');
        for(int i = 0; i <32 && i < n; i++){
            if(s[n-i-1] == '1'){
                long long temp = pow(2,i);
                if(temp >k) break;
                k-= temp;
                count++;
            }
        }
        return count;
    }
};