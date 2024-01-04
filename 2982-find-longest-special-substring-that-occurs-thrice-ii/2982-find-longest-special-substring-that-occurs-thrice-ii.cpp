class Solution {
public:
    int maximumLength(string s) {
        map <char,vector <int>> mp;
        int n = s.length();
        for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && s[i] == s[i + 1]) {
            count++;
            i++;
        }
        mp[s[i]].push_back(count);
    }
        for(auto &x:mp){
            sort(x.second.begin(),x.second.end());
        }
        int ans = 0;
        for(auto &x:mp){
            vector <int> cnt = x.second;
            int k = cnt.size();
            if(cnt.back() <= 2){
                if(cnt.back() == 2 && cnt.size() >=2){
                    ans = max(ans,min(cnt.back()-1,cnt[k-2]));
                }
                if(cnt.size()>=3){
                  ans = max(ans,min(cnt.back(),min(cnt[k-2],cnt[k-3])));
                }
            }
            else{
                ans = max(ans,cnt.back()-2);
                if(cnt.size() >=2){
                    ans = max(ans,min(cnt.back()-1,cnt[k-2]));
                }
                if(cnt.size()>=3){
                    ans = max(ans,min(cnt.back(),min(cnt[k-2],cnt[k-3])));
                }
            }
        }
        if(ans == 0) return -1;
        return ans;
    }
};