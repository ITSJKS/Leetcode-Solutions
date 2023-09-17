class Solution {
public:
    int depth(int u){
        return 32 -__builtin_clz(u);
    }
    int lca(int u, int v){
        if(depth(u) > depth(v)) swap(u,v);
        int d1 = depth(u);
        int d2 = depth(v);
        while(d2!=d1){
            v/=2;
            d2--;
        }
        while(u!=v){
            u/=2;
            v/=2;
        }
        return u;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector <int> ans;
        for(auto &x:queries){
            int u  =x[0] , v = x[1];
            int lc_a = lca(u,v);
            ans.push_back(depth(u) + depth(v) - 2*depth(lc_a) + 1);
        }
        return ans;
    }
};

/*
The node will be like this

1
2 3
4 5 6 7
8 9 10 11 12 13 14 15

for joining u -> v
we can find the level by number of bits
then we can find the lca using some binary search method
so cycle length will be equal to depth[u] + depth[v] - 2*depth[lca(u,v)] + 1
for finding lca we will use the bst method
}


*/