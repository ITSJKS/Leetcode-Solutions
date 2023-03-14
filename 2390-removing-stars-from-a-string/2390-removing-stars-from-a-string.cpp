class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto x:s){
            if(x!='*'){
                ans.push_back(x);
            }
            else{
                if(ans.size()){
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};