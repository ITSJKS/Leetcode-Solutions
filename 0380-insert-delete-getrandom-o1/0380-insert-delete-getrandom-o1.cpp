class RandomizedSet {
public:
    unordered_map <int,int> mp;
    RandomizedSet() {
        srand(time(0));

    }
    
    bool insert(int val) {
       if(mp.find(val)!=mp.end()){
           return false;
       }
       else{
           mp[val]= 1;
           return true;
       }
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
          mp.erase(val);
          return true;
       }
       else{
           return false;
       }
    }
    
    int getRandom() {
        
        int random = rand()%(mp.size());
        auto it = mp.begin() ;
        advance(it, random);
        return (*it).first;
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */