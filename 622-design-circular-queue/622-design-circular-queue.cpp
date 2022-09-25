class MyCircularQueue {
     vector <int> v;
     int K;
public:
    MyCircularQueue(int k) {
        K = k;
        
    }
    
    bool enQueue(int value) {
        if(v.size()<K){
            v.push_back(value);
            return true;
        }
        return false;
        
        
    }
    
    bool deQueue() {
        if(v.size()){
            v.erase(v.begin());
            return true;
        }
        return false;
    }
    
    int Front() {
        if(v.size()){
            return v[0];
        }
        else return -1;
    }
    
    int Rear() {
        if(v.size()) return v.back();
        return -1;
    }
    
    bool isEmpty() {
        return v.size() == 0;
    }
    
    bool isFull() {
        return v.size() == K;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */