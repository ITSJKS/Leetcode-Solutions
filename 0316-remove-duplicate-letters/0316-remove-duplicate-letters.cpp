class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string ans = "";
        unordered_map <char,int> mp;
        for(auto &x:s) mp[x]++;
        unordered_map <char,int> vis;
        for(int i = 0; i <n; i++){
            char ch = s[i];
            mp[ch]--;
            if(vis[ch]) continue;
            while(ans.size() && ans.back() > ch && mp[ans.back()]){
                vis[ans.back()] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            vis[ch] = 1;
        }
        return ans;
        
    }
};