class ThroneInheritance {
public:
    set <string> dead;
    unordered_map <string,vector<string>> tree;
    string king;
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        tree[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector <string> inheritance;
        dfs(tree,inheritance,king,dead);
        return inheritance;
    }
    void dfs(unordered_map <string,vector <string>>&tree,vector <string> &inheritance,string key,set<string> &dead){
    if(dead.count(key)==0) inheritance.push_back(key);
    for(auto nbr:tree[key]){
        dfs(tree,inheritance,nbr,dead);
    }
}
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */