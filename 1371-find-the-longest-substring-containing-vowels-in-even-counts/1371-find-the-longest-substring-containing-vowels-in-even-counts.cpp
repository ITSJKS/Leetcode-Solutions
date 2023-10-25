class Solution {
public:
    int findTheLongestSubstring(string s) {
        string vowels = "aeiou";
        // vowels even number of times
        unordered_map <int,int> mp;
        mp[0] = -1;
        int ans = 0;
        int cur_mask = 0;
        int n = s.size();
        for(int r = 0; r <n; r++){
            if(vowels.find(s[r])!=string::npos){
                cur_mask ^= (1<<(s[r]-'a'));
            }
            if(mp.count(cur_mask)){
                ans = max(ans, r-mp[cur_mask]);
            }
            else{
                mp[cur_mask] = r;
            }
        }
        return ans;
    }
};