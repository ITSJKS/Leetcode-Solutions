class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;

public:
    FooBar(int n) {
        this->n = n;
        this->turn = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock <mutex> lock(m);
            while(turn%2) cv.wait(lock);
        	printFoo();
            turn = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            unique_lock <mutex> lock(m);
            while((turn&1) == 0) cv.wait(lock);
        	printBar();
            turn = 0;
            cv.notify_all();
        }
    }
};