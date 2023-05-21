typedef pair<int, int> pii; // Pair of (node, weight)

const int INF = 1e9; // Infinite distance

// Function to perform Dijkstra's algorithm
int dijkstra(vector<vector<pii>>& graph, int source, int destination) {
    int n = graph.size();
    vector<int> dist(n, INF); // Initialize all distances as infinity
    vector<int> prev(n, -1); // Store the previous node in the shortest path
    vector<bool> visited(n, false);

    dist[source] = 0; // Distance from source to source is 0

    // Priority queue to store nodes based on their distances
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    // for(auto &x:dist) cout<<x<<" ";
    // cout<<endl;
    // Reconstruct the shortest path from source to destination
    return dist[destination];
}

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector <vector <pair<int,int>>> adj(n);
        vector <int> idx;
        int i = 0;
        for(auto &edge:edges){
            int u = edge[0] , v =edge[1] , w = edge[2];
            if(w == -1){
                idx.push_back(i);
            }
            else{
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }
            i++;
        }
        auto d = dijkstra(adj,source,destination);
        if(d < target) return {};
        if(d == target){
            for(auto &x:idx){
                edges[x][2] = 2*1e9;
            }
            return edges;
        }
        for(int i = 0; i <idx.size(); i++){
                edges[idx[i]][2] = 1;
                int u = edges[idx[i]][0] , v  = edges[idx[i]][1];
                adj[u].push_back({v,1});
                adj[v].push_back({u,1});
            // cout<<u<<" "<<v<<endl;
                int d = dijkstra(adj,source,destination);
                if(d <= target){
                    edges[idx[i]][2] += target - d;
                    for(int j = i+1; j <idx.size(); j++){
                        edges[idx[j]][2] = 2*1e9;
                    }
                    return edges;
                }
        }
        return {};
            }
};