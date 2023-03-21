class Solution {
public:
    int m;
    int n;
    int size;
    unordered_set <int> st;
    Solution(int m_, int n_) {
        m = m_;
        n = n_;
        size = m*n;
    }
    
    vector<int> flip() {
        int x = random()%size;
        while(st.count(x)!=0){
            x = random()%size;
        }
        st.insert(x);
        // cout<<x<<" ";
        return {x/n,x%n};
    }
    
    void reset() {
        st.clear();
    }
};
    // 0 1 2 3 4
    // 5 6 7 8 9
    // . . . . .
    // . . . . .
    // . . . . .
    // 21 4 th row 1st columns
    

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */