class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
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
            for(int j = 0; j <26; j++){
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