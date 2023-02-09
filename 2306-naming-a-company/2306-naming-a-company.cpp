class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set <string> st[26];
        int cnt[26][26] = {0};
        for(auto x:ideas){
            string s = x.substr(1);
            st[x[0]-'a'].insert(s);
        }
        for(int i = 0; i <26; i++){
            for(auto x:st[i]){
                for(int j = 0; j <26; j++){
                    cnt[i][j] += st[j].count(x)==0;
                }
            }
        }
        long long  count  = 0;
        for(int i = 0; i <26; i++){
            for(int j = 0; j <26; j++){
                count += cnt[i][j]*1ll*cnt[j][i];
            }
        }
        return count;
    }
};