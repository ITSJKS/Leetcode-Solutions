class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector <int> v(26,0);
        for(auto x:s) v[x-'a']++;
        int last = -1;
        for(int i = 0; i <26; i++){
            if(v[i] == 0) continue;
            else{
                if(last == -1) last = v[i];
                else if(v[i]!=last) return false;
            }
        }
        return true;
    }
};