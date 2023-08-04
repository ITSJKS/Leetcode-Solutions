class Solution {
    unordered_map <string , bool> mp;
public:
    bool search(string s, vector <string>& wd){
        for(string x:wd){
            if(s == x) return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wd) {
        int n  = s.length();
        if(mp.find(s)!=mp.end()) return mp[s];
        if(n == 0) return true;
        for(int i = 1; i <=n; i++){
            string st1 = s.substr(0,i);
            string st2 = s.substr(i,n-i);
            if(search(st1,wd) && wordBreak(st2,wd)) return mp[s] =  true;
        }
        return mp[s] =  false;
    }
};