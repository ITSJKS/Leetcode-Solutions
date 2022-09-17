class Solution {
    unordered_map <string,bool> pd;
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //brute force one will be forming all pairs and then checking if they r palindrome;
        vector <vector <int>> ans;
        int n = words.size();
        if(n<2) return {};
        unordered_map <string,int> mp;
        
        int i=0;
        for(auto x:words){
            reverse(x.begin(),x.end());
            mp[x] = i;
            i++;
        }
        
        // "" case
        
        
        if(mp.find("")!=mp.end()){
            for(int i = 0; i <n; i++){
                if(i==mp[""]) continue;
                if(isPalindrome(words[i])) ans.push_back({i,mp[""]});
            }
        }
        string part_1,part_2,temp;
        for(int i = 0; i <n; i++){
            string part_2 = words[i];
            string part_1 = "";
            for(int j = 0; j <words[i].size();j++){
                part_1.push_back(words[i][j]);
                part_2.erase(0,1);
                if(mp.find(part_1)!=mp.end() && isPalindrome(part_2) && mp[part_1]!=i) ans.push_back({i,mp[part_1]});
                if(mp.find(part_2)!=mp.end() && isPalindrome(part_1) && mp[part_2]!=i) ans.push_back({mp[part_2],i});
            }
        }
        return ans;
    }
    bool isPalindrome(string &s){
        if(pd.find(s)!=pd.end()) return pd[s];
        int i = 0, j = s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return pd[s] =  false;
            i++;
            j--;
        }
        return pd[s] = true;
    }
};
