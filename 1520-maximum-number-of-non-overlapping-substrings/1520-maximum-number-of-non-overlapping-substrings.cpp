class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map <char,pair<int,int>> mp;
        int n = s.size();
        for(int i = 0; i <n; i++){
            if(mp.count(s[i])){
                mp[s[i]].second = i;
            }
            else mp[s[i]] = {i,i};
        }
        vector <pair<int,int>> ans;
        for(auto &x:mp){
            char ch = x.first;
            int first = x.second.first;
            int second = x.second.second;
            for(int j = first; j <=second; j++){
                first = min(mp[s[j]].first,first);
                second = max(mp[s[j]].second,second);
            }
            if(first == x.second.first){
                ans.push_back({second,first});
            }
        }
        sort(ans.begin(),ans.end());
        vector <string> res;
        int prev = -1;
        for(int j = 0; j <ans.size(); j++){
            if(ans[j].second > prev){
                res.push_back(s.substr(ans[j].second,ans[j].first-ans[j].second+1));
                prev = ans[j].first;
            }
        }
        return res;   
    }
};
//if a is occuring from 0 to 2 and b from 1 to 1 we can just take b instead of a 
// we can merge the overlapping interval, and 
//abcabc abc abc
// can't be more than 26
// right
// because there will be atmost difference type of character 

// now we can try to find max

// we can first try to find all the substrings