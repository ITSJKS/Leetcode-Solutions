class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string ans = "";
        vector <int> mp(26,0);
        for(auto &x:s) mp[x-'a']++;
        vector <bool> vis(26,0);
        for(int i = 0; i <n; i++){
            char ch = s[i];
            mp[ch-'a']--;
            if(vis[ch-'a']) continue;
            while(ans.size() && ans.back() > ch && mp[ans.back()-'a']){
                vis[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            vis[ch-'a'] = 1;
        }
        return ans;
        
    }
};