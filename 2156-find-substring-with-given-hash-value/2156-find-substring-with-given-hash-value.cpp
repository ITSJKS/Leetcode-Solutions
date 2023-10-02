class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        vector <long long> powers(n);
        powers[0] = 1ll;
        for(int i =  1; i <n; i++){
            powers[i] = (powers[i-1]*1ll*power)%modulo;
        }
        vector <long long> hashes(n+1);
        for(int i = 0; i <n; i++){
            hashes[i+1] = (hashes[i] + ((s[i]-'a'+1)*1ll*powers[i])%modulo)%modulo;
        }
        auto check = [&](int ind){
            long long hash = 0;
            for(int i = ind; i <ind+k; i++){
                hash = (hash + ((s[i]-'a'+1)*1ll*powers[i-ind])%modulo)%modulo;
            }
            return hashValue == hash;
        };
        for(int i = 0; i - k + 1 <n; i++){
            long long cur_hash = (hashes[i+k] - hashes[i] + modulo)%modulo;
            if(cur_hash == (hashValue*1ll*powers[i])%modulo){
                if(check(i)) return s.substr(i,k);
            }
        }
        return "";
    }
};