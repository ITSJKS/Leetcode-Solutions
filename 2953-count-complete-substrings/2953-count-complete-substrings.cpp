class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        string cur;
        int n = word.size();
        int count  = 0;
        auto check = [&](string &s){
            int len= s.size();
            int cnt = 0;
            for(int uq = 1; uq <=26; uq++){
                if(uq*k > len) break;
                int req = uq*k;
                unordered_map <char,int> mp;
                auto isValid =[&](){
                    for(auto &x:mp){
                        if(x.second!=k) return false;
                    }
                    return true;
                };
                for(int j = 0; j <req; j++){
                    mp[s[j]]++;
                }
                cnt += isValid();
                for(int j = req; j<len; j++){
                    mp[s[j-req]]--;
                    if(mp[s[j-req]]==0){
                        mp.erase(s[j-req]);
                    }
                    mp[s[j]]++;
                    cnt += isValid();
                }
            }
            return cnt;
        };
        for(int i = 0; i <n; i++){
            cur.push_back(word[i]);
            if(i+1<n){
                if(abs(word[i+1]-word[i])>2){
                    count += check(cur);
                    cur = "";
                }
            }
        }
        count += check(cur);
        return count;
    }
};

// let's form all those seperate strings where there the difference between two adjacent character is at most 2
// then we can work on those strings as on those strings we can just apply a sliding window approach where we will check strings of length k , 2k , 3k , 4k , 5k .. 26k to find if there are 1 , 2, 3 , 4 , 5, .. unique characters of frequency k
