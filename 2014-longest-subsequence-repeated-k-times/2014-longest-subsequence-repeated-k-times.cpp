class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_set <char> st;
        vector  <int> freq(26,0);
        for(auto &x:s){
            freq[x-'a']++;
        }
        for(char ch = 'a'; ch<='z'; ch++) if(freq[ch-'a']>=k) st.insert(ch);
        int n = s.size();
        queue <string> q;
        q.push("");
        string ans;
        auto check = [&](string &temp){
            int j = 0;
            int count = 0;
            for(int i = 0; i <n; i++){
                if(s[i] == temp[j]) j++;
                if(j == temp.size()){
                    j = 0;
                    count++;
                }
                if(count == k) return true;
            }
            return false;
        };
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            vector <int> cnt(26,0);
            for(auto &x:cur){
                cnt[x-'a']++;
                if(cnt[x-'a']*k > freq[x-'a']) continue;
            }
            for(int j = 0; j <26; j++){
                if(st.count(j+'a') == 0) continue;
                string temp = cur + char(j+'a');
                if(check(temp)){
                    ans = temp;
                    q.push(temp);
                }
            }
        }
        return ans;
        
    }
};
/*
longest subsequnce repeated k times in string s



*/