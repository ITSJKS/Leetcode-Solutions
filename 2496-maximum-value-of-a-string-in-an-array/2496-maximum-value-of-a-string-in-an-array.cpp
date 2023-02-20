class Solution {
public:
    bool isValid(string &x){
        for(auto ch:x){
            if(!(ch>='0' && ch<='9')) return false;
        }
        return true;
    }
    int maximumValue(vector<string>& strs) {
        int maxi = 0;
        for(auto x:strs){
            if(isValid(x)){
                maxi = max(maxi,stoi(x));
            }
            else{
                maxi = max(maxi,(int)x.size());
            }
        }
        return maxi;
    }
};