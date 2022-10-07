class MyCalendarThree {
public:
    map <int,int> time;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        time[start]++;
        time[end]--;
        int curr = 0 , maxi = 0;
        for(auto& [a,b]:time){
            curr += b;
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */