class SeatManager {
public:
    set <int> u_res;
    SeatManager(int n) {
        for(int i = 1; i <=n; i++){
            u_res.insert(i);
        }
    }
    
    int reserve() {
        int x = *u_res.begin();
        u_res.erase(x);
        return x;
    }
    
    void unreserve(int seatNumber) {
        u_res.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */