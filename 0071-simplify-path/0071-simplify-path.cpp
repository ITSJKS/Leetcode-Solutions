class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        stack <string> st;
        string s;
        while(!ss.eof()){
            getline(ss,s,'/');
            if(s == ".") continue;
            else if(s == " ") continue;
            else if(s == "") continue;
            else if(s == ".."){
                if(st.size()) st.pop();
            }
            else{
                st.push(s);
            }
        }
        string ans = "/";
        vector <string> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        for(auto x:v){
            // cout<<x<<" ";
            ans += x;
            ans += "/";
        }
        if(v.size()) ans.pop_back();
        return ans;
    }
};