class LockingTree {
public:
    unordered_map <int,vector <int>> g;
    unordered_map <int,int>mp;
    vector <int> parent;
    LockingTree(vector<int>& p):parent(p) {
        int n = p.size();
        for(int i  =0; i <n; i++){
            g[p[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(mp.find(num)!=mp.end()){
            return false;
        }
        mp[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(mp.find(num) == mp.end()) return false;
        if(mp[num] != user){
            return false;
        } 
        mp.erase(num);
        return true;
    }
    bool dfs(int src){
        bool flag = false;
        if(mp.find(src)!=mp.end()){
            flag = true;
        }
        for(auto nbr:g[src]){
            flag |= dfs(nbr);
        }
        return flag;
    }
    bool check_parent(int num){
        if (num == -1) return false;
        if (mp.find(num) != mp.end()) return true;
        return check_parent(parent[num]);
    }
    void unlock_child(int src){
        for(auto nbr:g[src]){
            mp.erase(nbr);
            unlock_child(nbr);
        } 
    }
    bool upgrade(int num, int user) {
        if(mp.find(num)!=mp.end()) return false;
        if(dfs(num) && !check_parent(parent[num])){
                unlock_child(num);
                mp[num] = user;
                return true;
            }
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */