class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string word) {
        int n = word.size();
        vector <vector <string>> res(n);
        auto check = [&](string &s){
            int i = 0;
            int m= s.size();
            while(i < m && i < n){
                if(s[i] == word[i]) res[i].push_back(s);
                else break;
                i++;
            }
        };
        for(int i = 0; i <products.size(); i++){
            string cur_word = products[i];
            check(cur_word);
        }
        for(auto &x:res){
            sort(x.begin(),x.end());
            int size = x.size();
            if(size >3)
            x.resize(3);
        }
        return res;
    }
};