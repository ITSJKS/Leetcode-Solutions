class MyCalendarTwo {
public:
    map <int,int> mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int cur = 0,maxi = 0;
        for(auto &[a,b]:mp){
            cur += b;
            maxi = max(cur,maxi);
            if(maxi >=3){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */