class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        while(s.size()){
        bool flag = false;
            string prev = "";
            for(int  i = s.size()-1; i >=0 ; i--){
                if(i > 0 && abs(s[i] - s[i-1]) == 32){
                    flag = true;
                    i--;
                }
                else{
                    prev.push_back(s[i]);
                }
            }
                reverse(prev.begin(),prev.end());
                s = prev;
            // cout<<s<<" ";
                if(!flag) return prev;
        }
        return s;
    }
};