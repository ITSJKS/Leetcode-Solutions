class Solution {
public:
    bool canChange(string s, string t) {
        string s_,t_;
        int n = s.size();
        vector <int> l_s,l_t,r_s,r_t;
        for(int i = 0; i <n; i++){
            if(s[i]!='_') s_.push_back(s[i]);
            if(t[i]!='_') t_.push_back(t[i]);
            if(s[i] == 'L'){
                l_s.push_back(i);
            }
            else if(s[i] == 'R'){
                r_s.push_back(i);
            }
            if(t[i] == 'L'){
                l_t.push_back(i);
            }
            else if(t[i] == 'R'){
                r_t.push_back(i);
            }
        }
        if(s_!=t_) return false;
        for(int i = 0; i <l_s.size(); i++){
            if(l_s[i]<l_t[i]) return false;
        }
        for(int i = 0; i <r_s.size(); i++){
            if(r_s[i]>r_t[i]) return false;
        }
        return true;
    }
};