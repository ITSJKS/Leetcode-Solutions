class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set <int> st;
        for(auto x:nums) st.insert(x);
        if(st.size() >=3){
            st.erase(*st.rbegin());
            st.erase(*st.rbegin());
            return *st.rbegin();
        }
        return *st.rbegin();
    }
};