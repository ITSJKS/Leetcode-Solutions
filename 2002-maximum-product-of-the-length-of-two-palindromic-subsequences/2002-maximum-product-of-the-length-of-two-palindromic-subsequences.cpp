class Solution {
public:
    bool isPalindrome(string s){
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int maxProduct(string s) {
        map <int,int> mp;
        int n = s.size();
        for(int i = 1; i<(1<<n); i++){
            string temp ="";
            for(int j = 0; j <n; j++){
                if(i&(1<<j)) temp.push_back(s[j]);
            }
            if(isPalindrome(temp)){
                // cout<<temp<<" ";
                mp[i] = temp.size();
            }
        }
        int ans = 0;
        for(auto x:mp){
            for(auto y:mp){
                // cout<<x.first<<" "<<y.first<<endl;
                if((x.first&y.first) == 0){
                    ans = max(ans,x.second*y.second);
                }
            }
        }
        return ans;
    }
};