class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();
        for(int i = 0; i <n-2; i++){
            string t = num.substr(i,3);
            bool check = true;
            for(int i = 1; i <t.size(); i++){
                if(t[i] != t[i-1])  check = false;
            }
            if(check) ans = max(ans,t);
        }
        return ans;
    }
};