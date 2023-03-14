class Solution {
public:
    string removeStars(string s) {
        stack <char> st;
        for(auto x:s){
            if(x!='*'){
                st.push(x);
            }
            else{
                if(st.size()){
                    st.pop();
                }
            }
        }
        string ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};