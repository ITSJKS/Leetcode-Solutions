class Allocator {
public:
    vector <int> v;
    Allocator(int n_) {
        v.resize(n_,0);
    }
    
    int allocate(int size, int mID) {
        int count = 0;
        int ans = -1;
        for(int i = 0; i <v.size(); i++){
            if(v[i] == 0){
                if(count == 0)ans = i;
                count++;
                if(count == size){
                    for(int j = 0; j <count; j++){
                        v[j+ans] = mID;
                    }
                    return ans;
                }
            }
            else{
                count = 0;
                ans = -1;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int count = 0;
        for(int i = 0; i <v.size(); i++){
            if(v[i] == mID){
                v[i] = 0;
                count++;
            }
        }
        return count;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */