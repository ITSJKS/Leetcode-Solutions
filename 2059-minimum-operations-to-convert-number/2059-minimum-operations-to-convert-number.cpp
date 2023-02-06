class Solution {
public:
    int in_range(int x){
        return x>=0 && x<=1000;
    }
    int minimumOperations(vector<int>& nums, int start, int goal) {
        unordered_set <int> st;
        queue <int> q;
        q.push(start);
        st.insert(start);
        int count = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i <size; i++){
                int top = q.front();
                q.pop();
            for(auto x:nums){
                int add = top+x;
                int sub = top - x;
                int x_or = top ^ x;
                if(add == goal || sub == goal || x_or == goal) return count;
                if(in_range(add) && st.count(add)==0){
                    q.push(add);
                    st.insert(add);
                }
                if(in_range(sub) && st.count(sub)==0){
                    q.push(sub);
                    st.insert(sub);
                }
                if(in_range(x_or) && st.count(x_or)==0){
                    q.push(x_or);
                    st.insert(x_or);
                }
            }
            }
            count++;
        }
        return -1;
    }
};