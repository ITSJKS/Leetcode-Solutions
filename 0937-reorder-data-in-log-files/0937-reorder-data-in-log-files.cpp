class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto cmp = [&](string &a, string &b){
            int type1 = a.find(" ");
            int type2 = b.find(" ");
            string a1 = a.substr(0,type1);
            string a2 = a.substr(type1+1);
            string b2 = b.substr(type2 +1);
            string b1 = b.substr(0,type2);
            if(a2 == b2) return a1 < b1;
            return a2 < b2;
        };
        vector <string> letter;
        vector <string> digits;
        for(auto &x:logs){
            int type1 = x.find(" ");
            if(x[type1 + 1]>='0' && x[type1 + 1]<='9'){
                digits.push_back(x);
            }
            else letter.push_back(x);
        }
        sort(letter.begin(),letter.end(),cmp);
        for(auto &x:digits) letter.push_back(x);
        return letter;
    }
};