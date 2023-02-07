class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set <int> st;
        set <int> st_f;
        for(auto x:arr){
            set <int> st2;
            st.insert(x);
            for(auto y:st){
                st2.insert(y|x);
            }
            for(auto x:st2) st_f.insert(x);
            st =  st2;
        }
        return st_f.size();
    }
};