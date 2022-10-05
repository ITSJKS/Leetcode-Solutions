class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map <char,int> f;
        for(auto x:s){
            f[x]++;
        }
        int count = 0;
        for(auto x:s){
            if(f[x]>=k) count++;
            else break;
        }
        if(count == s.size()) return count;
        int left = longestSubstring(s.substr(0,count),k);
        int right = longestSubstring(s.substr(count+1),k);
        return max(left,right);
    }
};