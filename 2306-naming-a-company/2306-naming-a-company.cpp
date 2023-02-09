class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set <string> st[26];
        long long count = 0;
        for(auto x:ideas){
            st[x[0]-'a'].insert(x.substr(1));
        }
        for(int i = 0; i <26; i++){
            if(st[i].size() == 0) continue;
            for(int j = i+1; j <26; j++){
                if(st[j].size() == 0) continue;
                long long cnt1 = 0, cnt2 = 0;
                for(auto x:st[i]){
                    if(st[j].count(x) == 0) cnt1++;
                }
                for(auto x:st[j]){
                    if(st[i].count(x) == 0) cnt2++;
                }
                count += cnt1*cnt2*2;
            }
        }
        return count;
    }
};