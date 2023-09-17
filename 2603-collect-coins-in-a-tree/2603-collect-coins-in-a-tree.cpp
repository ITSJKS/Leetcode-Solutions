class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector <int> indegree(n);
        vector <vector <int>> g(n);
        for(auto &x:edges){
            int u = x[0] , v = x[1];
            indegree[v]++;
            indegree[u]++;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue <int> q;
        for(int i = 0; i <n; i++){
            if(indegree[i] == 1 && coins[i] == 0) q.push(i);
        }
        int rem = n;
        while(!q.empty()){
            int size = q.size();
            for(int j = 0; j <size; j++){
                int node = q.front();
                q.pop();
                rem--;
                for(auto &nbr:g[node]){
                    indegree[nbr]--;
                    if(indegree[nbr] == 1 && coins[nbr] == 0) q.push(nbr);
                }
                indegree[node] = 0;
            }
        }
        queue <int> q1;
        for(int i = 0; i <n; i++){
            if(indegree[i] == 1 && coins[i] == 1) q1.push(i);
        }
        for(int i = 0; i <2;i++){
            int size = q1.size();
            for(int j = 0; j <size; j++){
                int node = q1.front();
                q1.pop();
                rem--;
                for(auto &nbr:g[node]){
                    indegree[nbr]--;
                    if(indegree[nbr] == 1) q1.push(nbr);
                }
                indegree[node] = 0;
            }
        }
        if(rem - 1 < 0) return 0;
        return 2*(rem-1);
        
    }
};

/*
Given an undirected tree with n nodes so n - 1 edges
coins array of size n where coins[i] can be either 0 or 1 where 1 indicates the presence of a coin in the vertex i
operations :
->collect all the coins that are at distance at most 2 from the current vertex
->move to any adjacent vertex in the tree

We need to find minimum number of edges we need to go through to collect all the coins and go back to initial vertex

hint1 -> we need to delete leaves that are not containing coins

then we will have a tree where each leaves contains a coin

we can just pass all these coins to their parent's parent in one  moves , as we can just collect all these coins by just visiting their parent's parent
when all these coins reach their parent's parent we will again remove all those nodes which doesnot contains any coins as they will redundant
*/