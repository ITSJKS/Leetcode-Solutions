class DiningPhilosophers {
public:
    mutex m;
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
        
        m.lock();
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        m.unlock();
    }
};