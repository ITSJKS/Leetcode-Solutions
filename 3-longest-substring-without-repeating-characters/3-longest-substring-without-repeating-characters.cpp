class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> freq(256,-1);
        int left = 0, right = 0,maxi = 0;
        while(right<s.size()){
            if(freq[s[right]]!=-1) left = max(freq[s[right]]+1,left);
            freq[s[right]] = right;
            maxi = max(maxi,right-left+1);
            right++; 
        }
        return maxi;
    }
};