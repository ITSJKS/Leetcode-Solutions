class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long mod =  1e9 + 7;
        long long base = 2;
        int n = s.size();
        vector <long long> power(n);
        power[0] = 1;
        for(int i=1; i <n; i++) power[i] = (power[i-1]*1ll*base)%mod;
        vector <long long> hashes(n+1);
        for(int i = 0; i <n; i++){
            hashes[i+1] = (hashes[i] + (s[i]-'0'+1)*power[i])%mod;
        }
        unordered_set <int> st;
        for(int i = 0; i+k<=n; i++){
            long long hash = (hashes[i+k]-hashes[i]+mod)%mod;
            hash = (hash*power[n-i-1])%mod;
            st.insert(hash);
        }
        int cnt = st.size();
        // cout<<cnt<<endl;
        return cnt == (1<<k);
    }
};