class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set <int> st;
        unordered_set <int> st_f;
        for(auto x:arr){
            unordered_set <int> st2;
            st.insert(x);
            for(auto y:st){
                st2.insert(y|x);
                st_f.insert(y|x);
            }
            st_f.insert(x);
            st =  st2;
        }
        return st_f.size();
    }
};