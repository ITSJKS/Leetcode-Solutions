class BrowserHistory {
public:
    stack <string> st,st_f;
    BrowserHistory(string homepage) {
        st.push(homepage);
    }
    
    void visit(string url) {
        st.push(url);
        if(st_f.size()){
            while(st_f.size()) st_f.pop();
        }
    }
    
    string back(int steps) {
        steps = min(steps,(int)st.size()-1);
        int count = 0;
        while(count <steps){
            st_f.push(st.top());
            st.pop();
            count++;
        }
        return st.top();
    }
    
    string forward(int steps) {
        int count = 0;
        while(st_f.size() && count < steps){
            st.push(st_f.top());
            st_f.pop();
            count++;
        }
        return st.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */