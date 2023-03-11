class SeatManager {
public:
    priority_queue <int,vector <int>,greater<int>> pq;
    int maxi = 1;
    SeatManager(int n) {
        
    }
    
    int reserve() {
        int ans = pq.empty()?maxi++:pq.top();
        if(!pq.empty()) pq.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */