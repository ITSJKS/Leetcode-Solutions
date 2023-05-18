class FreqStack {
public:
    unordered_map <int,int> freq;
    unordered_map <int,stack <int>> freqStack;
    int maxi = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxi = max(maxi,freq[val]);
        freqStack[freq[val]].push(val);
    }
    
    int pop() {
        int ans = freqStack[maxi].top();
        freqStack[maxi].pop();
        freq[ans]--;
        if(freqStack[maxi].size() == 0) maxi--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */