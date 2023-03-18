class BrowserHistory {
public:
    stack <string> st,st_f;
    string current;
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        st.push(current);
        current = url;
        st_f = stack <string>();
    }
    
    string back(int steps) {
        while(steps>0 && !st.empty()){
            st_f.push(current);
            current = st.top();
            st.pop();
            steps--;
        }
        return current;
    }
    
    string forward(int steps) {
        while(steps > 0 && !st_f.empty()){
            st.push(current);
            current = st_f.top();
            st_f.pop();
            steps--;
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */