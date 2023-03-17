class CountIntervals {
public:
    int cnt;
    map <int,int> mp;
    CountIntervals() {
        cnt = 0;
    }
    
    void add(int left, int right) {
        auto it = mp.upper_bound(left);
        if(it!=mp.begin() && prev(it)->second >= left){
            it = prev(it);
        }
        while(it!=mp.end() && it->first <= right){
            left = min(left,it->first);
            right = max(right,it->second);
            cnt -= (it->second - it->first + 1);
            it = mp.erase(it);
        }
        cnt += right - left + 1;
        mp[left] = right;
        
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */