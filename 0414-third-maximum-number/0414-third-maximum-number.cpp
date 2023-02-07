class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set <int> st;
        for(auto x:nums){
            if(st.count(x)) continue;
            if(st.size()<3)
            st.insert(x);
            else if(*st.begin() < x){
                st.erase(*st.begin());
                st.insert(x);
            }
        }
        if(st.size() >=3){
            st.erase(*st.rbegin());
            st.erase(*st.rbegin());
            return *st.rbegin();
        }
        return *st.rbegin();
    }
};