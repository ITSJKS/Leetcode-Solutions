typedef pair<int,int> pii;
class Solution {
public:
    
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector <vector <int>> g(n);
        for(auto &x:edges){
            int u  =x[0]-1, v = x[1]-1;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector <int> dist1(n,1e9),dist2(n,1e9);
        queue <pii> pq;
        pq.push({0,0});
        dist1[0] = 0;
        while(!pq.empty()){
            auto [d,node] = pq.front();
            pq.pop();
            for(auto &nbr:g[node]){
                int nd = d + time;
                int turn = (d+change-1)/change;
                if ((d / change) % 2 == 1){
                    nd += change - (d % change);
                }
                if(dist1[nbr] > nd){
                    dist2[nbr] = dist1[nbr];
                    dist1[nbr] = nd;
                    pq.push({nd,nbr});
                }
                else if(dist2[nbr] > nd && dist1[nbr] < nd){
                    dist2[nbr] = nd;
                    pq.push({nd,nbr});
                }
            }
        }
        return dist2.back();
    }
};