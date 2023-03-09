class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        string ans =  "";
        int cnt = 0;
        for(int i = 0; i <n; i++){
            if(cnt < m && i == spaces[cnt]){
                ans.push_back(' ');
                cnt++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};