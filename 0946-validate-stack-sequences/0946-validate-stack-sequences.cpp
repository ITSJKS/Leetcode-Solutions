class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i = 0, j = 0;
        stack<int> st;
        while(i < n && j < n){
            while(i < n && (st.empty() || st.top()!=popped[j])){
                st.push(pushed[i]);
                i++;
            }
            while(st.size() && (st.top() == popped[j])){
                st.pop();
                j++;
            }
        }
        return st.size() == 0;
    }
};