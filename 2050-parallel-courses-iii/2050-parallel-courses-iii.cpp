class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        queue <int> q;
        vector <vector <int>> adj(n+1);
        vector <int> indegree(n+1);
        for(int i = 0; i <relations.size(); i++){
            int u = relations[i][0] ,  v = relations[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector <int> dist(n+1);
        for(int i =1; i <=n; i++){
            if(indegree[i] == 0) q.push(i),dist[i] = time[i-1];
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &nbr:adj[node]){
                dist[nbr] = max(dist[nbr],dist[node] + time[nbr-1]);
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        return *max_element(dist.begin(),dist.end());
        
    }
};

// we can apply kahn's algorithm but we can keep level maximum 
// I mean all nodes with indegree 0 will have level 0, when their neighbour are pushed into the queue there level will help us in finding level maximum 
// the answer will be sum of all level maximums