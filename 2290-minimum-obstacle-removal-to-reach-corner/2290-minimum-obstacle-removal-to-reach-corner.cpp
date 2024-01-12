class Solution {
public:
    
    vector <int> dir = {-1,0,1,0,-1};
    int shortest_path(vector <vector <pair<int,int>>>&g){
        int size = g.size();
        vector <int> dist(size,1e9);
        set <pair<int,int>> st;
        dist[0] = 0;
        st.insert({0,0});
        while(st.size()){
            int node = st.begin()->second;
            st.erase(st.begin());
            for(auto &nbr:g[node]){
                int nbr_node = nbr.first;
                int weight = nbr.second;
                if(dist[node] + weight < dist[nbr_node]){
                    st.erase({dist[nbr_node],nbr_node});
                    dist[nbr_node] = dist[node]+weight;
                    st.insert({dist[nbr_node],nbr_node});
                }
            }
        }
        return dist.back();
        
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size = n*m;
        vector <vector <pair<int,int>>>g(n*m);
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                for(int k = 0; k <4; k++){
                    int nx = i + dir[k];
                    int ny = j + dir[k+1];
                    if(nx >= 0 && nx < n && ny >=0 && ny < m){
//                         if(grid[i][j]){
//                             g[nx*n + ny].push_back({i*n + j,1});
                            
//                         }
//                         else{
//                             g[nx*n + ny].push_back({i*n + j,0});
//                         }
                        if(grid[nx][ny]){
                            g[i*m+j].push_back({nx*m+ny,1}); 
                        }
                        else{
                            g[i*m+j].push_back({nx*m+ny,0});
                        }
                    }
                }
            }
        }
        return shortest_path(g);
    }
};
/*
we can define cost of an obstacle to be 1
if we are allowed to move through the obstacle and just get minimum cost that would have made us reach to the end
we can apply dijkstra here
we can create nodes of size n*m and for each node we can assign cost to reach 

*/