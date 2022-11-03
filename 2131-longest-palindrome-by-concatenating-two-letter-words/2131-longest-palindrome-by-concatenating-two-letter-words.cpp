class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map <string,int> mp;
        for(auto &x:words){
            // sort(x.begin(),x.end());
            mp[x]++;
        }
        int len =0;
        bool exist = false;
        for(auto w:words){
            string x = w;
            reverse(x.begin(),x.end());
            if(x!=w && mp[x] && mp[w]){
                len += 4;
                mp[x]--;
                mp[w]--;
            }
            else if(x == w && mp[w]>1){
                len+=4;
                mp[w]-=2;
            }
            else if(x == w && !exist && mp[x]){
                len += 2;
                mp[x]--;
                exist = true;
            }
        }
        return len;
    }
};