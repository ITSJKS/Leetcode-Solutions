class SmallestInfiniteSet {
public:
    int cnt = 1;
    set <int> st;
    SmallestInfiniteSet() {

    }
    
    int popSmallest() {
        if(!st.empty()){
            int ans;
            int top = *st.begin();
            ans = top;
            st.erase(top);
            return ans;

        }
        return cnt++;
    }
    
    void addBack(int num) {
        if(num < cnt) st.insert(num);
    }
};



/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */