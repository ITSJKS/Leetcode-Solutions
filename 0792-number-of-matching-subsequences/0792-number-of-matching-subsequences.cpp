class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map <char,vector <int>> mp;
        for(int i = 0; i <s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int count = 0;
        for(auto &x:words){
            int ind = -1;
            bool check = true;
            for(auto &y:x){
                if(mp.count(y) == 0){
                    check = false;
                    break;
                }
                auto it = upper_bound(mp[y].begin(),mp[y].end(),ind);
                if(it == mp[y].end()){
                    check = false;
                    break;
                }
                ind = *it;
            }
            if(check) count++;
        }
        return count;
    }
};

/*
One of the approach would be to put every word in a trie, then we can traverse the string 
if current character is x and then out of all those nodes I will take them to that node if 


*/