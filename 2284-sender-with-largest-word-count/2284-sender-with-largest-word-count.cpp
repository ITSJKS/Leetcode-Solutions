class Solution {
public:
    bool comp(string  a, string  b){
        return a > b;
    }
    int find_word(string s){
        int count = 0;
        for(int i  = 0 ; i <s.length(); i++){
            if(s[i] == ' ') count++;
        }
        return count+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map <string,int> mp;
        for(int i = 0; i <senders.size(); i++){
            mp[senders[i]] += find_word(messages[i]);
        }
        int largest = -1;
        string ans = "";
        for(auto x:mp){
            if(x.second > largest){
                largest = x.second;
                ans = x.first;
            }
            else if(x.second == largest){
                ans = comp(x.first,ans)?x.first:ans;
            }
        }
        return ans;
    }
};