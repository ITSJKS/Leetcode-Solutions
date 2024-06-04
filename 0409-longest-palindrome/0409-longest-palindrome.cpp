class Solution {
public:
    int longestPalindrome(string s) {
        map <int,int> mp;
        for(auto &x:s){
            mp[x]++;
        }
        int count = 0;
        bool odd = false;
        for(auto &x:mp) 
            if(x.second&1) 
            count += x.second-1,odd = true;
            else count += x.second;
        return count + odd;
    }
};