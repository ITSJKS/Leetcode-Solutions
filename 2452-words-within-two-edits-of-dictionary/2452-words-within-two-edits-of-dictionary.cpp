class Solution {
public:
    bool check(string &s, string &t){
        int count = 0;
        for(int i =0; i <s.size(); i++){
            if(s[i]!=t[i]) count++;
            if(count > 2) return false;
        }
        return count <= 2;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector <string> ans;
        for(auto word:queries){
            for(auto x:dictionary){
                if(word.size() == x.size() && check(word,x)){
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};