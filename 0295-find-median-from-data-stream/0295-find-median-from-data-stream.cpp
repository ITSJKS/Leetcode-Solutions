class MedianFinder {
public:
    priority_queue <int> first;
    priority_queue <int,vector <int>,greater<int>> second;
    int size;
    void maintain(){
        int size1 = first.size();
        int size2 = second.size();
        if(size1 - size2>1){
            int top = first.top();
            first.pop();
            second.push(top);
        }
        else if(size2 > size1){
            int top = second.top();
            second.pop();
            first.push(top);
        }
    }
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        int size1 = first.size();
        int size2 = second.size();
        if(size2 && second.top() <= num) second.push(num);
        else first.push(num);
        maintain();
        size++;
    }
    
    double findMedian() {
        if(size&1) return first.top();
        else return (first.top() + second.top())/(2*1.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// we can keep two priority_queue
// one will be max heap and other one will be min heap

// we will also maintain their size , if size of our data is even then we can find top of first and second one and return their average
// if size of the data is odd then we will return top of the first priority_queue