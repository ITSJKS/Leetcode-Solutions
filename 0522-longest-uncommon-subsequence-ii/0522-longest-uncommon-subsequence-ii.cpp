class Solution {
public:
    bool check(string &s, string &t){
        int i = 0, j = 0;
        while(i < t.size() && j < s.size()){
            if(t[i] == s[j]) i++,j++;
            else i++;
        }
        return j == s.size();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),[&](string &a, string &b){
            return a.size() > b.size();
        });
        unordered_map <string,int> mp;
        for(auto x:strs) mp[x]++;
        int n = strs.size();
        for(int i = 0; i <n; i++){
            
            if(mp[strs[i]] == 1){
                bool unique = true;
                for(int j = 0; j < i; j++){
                    if(check(strs[i],strs[j])) unique = false;
                }
                if(unique) return strs[i].size();
            }
        }
        return -1;
    }
};