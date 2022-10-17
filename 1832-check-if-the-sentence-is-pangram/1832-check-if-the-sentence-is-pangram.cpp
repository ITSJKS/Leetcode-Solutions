class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector <bool> v(26,false);
        for(auto c:sentence){
            v[c-'a']=true;
        }
        for(auto x:v){
            if(x==false) return false;
        }
        return true;
    }
};