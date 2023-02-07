class Solution {
public:
    string diff(string x){
        string ans = "";
        int n = x.size();
        for(int i = 1; i <n; i++){
            ans += x[i]-x[i-1];
        }
        return ans;
    }
    string oddString(vector<string>& words) {
        unordered_map <string,vector <string>> mp;
        for(auto x:words){
           string d =diff(x);
            mp[d].push_back(x);
        }
        for(auto x:mp){
            if(x.second.size() == 1) return x.second[0];
        }
        return "";
    }
};