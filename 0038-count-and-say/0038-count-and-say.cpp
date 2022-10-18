class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n == 2) return "11";
        string s = countAndSay(n-1);
        string res = "";
        int count1= 1;
        for(int i = 1; i<s.length(); i++){
            if(s[i] == s[i-1]){
                count1++;
            }
            else{
                res += (to_string(count1));
                res.push_back(s[i-1]);
                count1 = 1;
            }
            if(i == s.size()-1){
            res += to_string(count1);
                res.push_back(s[i]);
        }
        }
        return res;
    }
};