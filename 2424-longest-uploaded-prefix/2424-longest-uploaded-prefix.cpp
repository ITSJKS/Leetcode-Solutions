class LUPrefix {
    set <int> v;
    int l = 0;
public:
    LUPrefix(int n) {
    }
    
    void upload(int video) {
        v.insert(video);
        
    }
    
    int longest() {
        while(v.count(l+1)) l++;
        return l;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */