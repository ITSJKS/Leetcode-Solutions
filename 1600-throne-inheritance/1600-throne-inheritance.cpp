class ThroneInheritance {
public:
    unordered_set <string> dead;
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
        dfs(inheritance,king);
        return inheritance;
    }
    void dfs(vector <string> &inheritance,string key){
    if(dead.count(key)==0) inheritance.push_back(key);
    for(auto nbr:tree[key]){
        dfs(inheritance,nbr);
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