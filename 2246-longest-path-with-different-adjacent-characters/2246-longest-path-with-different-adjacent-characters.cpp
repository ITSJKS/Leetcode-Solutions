class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector <vector <int>> g(n);
        for(int i = 1; i <n; i++){
            g[parent[i]].push_back(i);
        }
        int ans = 0;
        function <int(int,int)> dfs = [&](int src , int par){
            int first = 0;
            int second = 0;
            char ch = s[src];
            for(auto &nbr:g[src]){
                if(nbr == par) continue;
                int val2 = dfs(nbr,src);
                if(ch != s[nbr]){
                    if(val2 >= first){
                        second = first;
                        first = val2;
                    }
                    else if(val2 > second){
                        second = val2;
                    }
                }
            }
            ans = max(ans , 1+ first + second);
            return 1 + first;
        };
        dfs(0,-1);
        return ans;
    }
};


/*
we are given a tree rooted at node 0
string s of length n where s[i] is the character assigned to node i

length of longest path in the tree such that no pair of adjancent nodes on the path have the same charcter assigned to them


*/