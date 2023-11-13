class Solution {
public:
    string sortVowels(string s) {
        string t = "AEIOUaeiou";
        unordered_set<char> st;
        vector <char> vowels;
        for(auto &x:t) st.insert(x);
        for(auto &x:s){
            if(st.count(x)){
              vowels.push_back(x);
            }
        }
        sort(vowels.begin(),vowels.end());
        int idx = 0;
        for(auto &x:s){
            if(st.count(x)){
                x = vowels[idx];
                idx++;
            }
        }
        return s;
    }
};