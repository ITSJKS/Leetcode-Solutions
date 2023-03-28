class TreeAncestor {
    vector <vector <int>> up;
    vector <int> depth;
     int LOG = 20;
public:
    TreeAncestor(int n, vector<int>& parent) {
        up = vector <vector <int>> (n,vector <int>(LOG,0));
        parent[0] = 0;
        depth.assign(n,0);
        for(int node = 0; node <n; node++){
            up[node][0] = parent[node];
        }
        for(int j= 1; j < LOG; j++){
            for(int node = 0; node <n; node++){
            if(node!=0) depth[node] = depth[parent[node]] + 1;
                up[node][j] = up[ up[node][j-1] ][j-1];
            }       
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k) return -1;
        for(int j = 0; j < LOG; j++){
            if(k&(1<<j)){
                node = up[node][j];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */