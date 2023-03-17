class MyCalendarThree {
public:
    map <int,int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int sT, int eT) {
        int cur = 0, ans = 0;
        mp[sT]++;
        mp[eT]--;
        for(auto x:mp){
            cur += x.second;
            ans = max(ans,cur);
        }
        return ans;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */