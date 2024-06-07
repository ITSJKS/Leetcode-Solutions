class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map <string,int> mp;
        for(auto x:dictionary){
            mp[x]++;
        }
        stringstream ss(sentence);
        string s;
        string ans = "";
        while(ss>>s){
            int n = s.size();
            bool found = false;
            for(int i = 1; i <=n; i++){
                string prefix = s.substr(0,i);
                if(mp.find(prefix)!=mp.end()){
                ans += prefix;
                found = true;
                break;
                }     
            }
            if(!found) ans += s;
            ans +=" ";
        }
        ans.pop_back();
        return ans;
    }
};