class Solution {
public:
    int partitionString(string s) {
        unordered_set <char> st;
        int count = 0;
        for(auto x:s){
            if(st.empty()){
                st.insert(x);
                count++;
            }
            else if(st.find(x)!=st.end()){
                st.erase(st.begin(),st.end());
                st.insert(x);
                count++;
            }
            else{
                st.insert(x);
            }
        }
        return count;
    }
};