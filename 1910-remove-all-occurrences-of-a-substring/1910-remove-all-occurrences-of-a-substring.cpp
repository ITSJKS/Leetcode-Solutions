class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!=string::npos){
            int idx = s.find(part);
            s.replace(idx,part.size(),"");
        }
        return s;
    }
};