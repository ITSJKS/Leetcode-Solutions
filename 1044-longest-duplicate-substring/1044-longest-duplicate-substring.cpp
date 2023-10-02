class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        vector <long long> powers(n);
        powers[0] = 1;
        int mod =  1e9 + 7;
        int base = 26;
        for(int i = 1; i <n; i++){
            powers[i] = (powers[i-1]*1ll*base)%mod;
        }
        vector <long long> hashes(n+1,0);
        for(int i = 0; i <n; i++){
            hashes[i+1] = (hashes[i] + ((s[i]-'a'+1)*1ll*powers[i])%mod)%mod;
        }
        string ans="";
        unordered_map <long long,vector <int>> mp;
        auto check = [&](int len){
            if(len == 0) return true;
            for(int i = 0; i <=n-len; i++){
                long long cur_hash = (hashes[i+len] - hashes[i]+mod)%mod;
                cur_hash  = (cur_hash*1ll*powers[n-i-1])%mod;
                if(mp.count(cur_hash)){
                    string t = s.substr(i,len);
                    for(auto &x:mp[cur_hash]){
                        string match = s.substr(x,len);
                        if(t == match){
                            if(ans.size() <= t.size()) ans = t;
                            return true;
                        }
                    }
                }
                mp[cur_hash].push_back(i);
            }
            return false;
        };
        int l = -1 , r = n+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        return ans;
    }
};