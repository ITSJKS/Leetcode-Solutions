class Node{
    public:
    int node;
    int mask;
    int cost;
    Node(int node, int mask, int cost){
        this->node  = node;
        this->mask = mask;
        this->cost = cost;
    }
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue <Node> q;
        int n = graph.size();
        int final_mask = (1<<n)-1;
        set <pair<int,int>> st;
        for(int i = 0; i <n; i++){
            int mask = 1<<i;
            Node node = Node(i,mask,1); 
            q.push(node);
            st.insert({i,mask});
        }
        while(!q.empty()){
            Node f = q.front();
            int node = f.node;
            int mask = f.mask;
            int cost = f.cost;
            q.pop();
            if(mask == final_mask) return cost - 1;
            for(auto &nbr:graph[node]){
                int bitmask = mask | (1<<nbr);
                if(st.count({nbr,bitmask})==0){
                    Node new_node = Node(nbr,bitmask,cost+1);
                    q.push(new_node);
                    st.insert({nbr,bitmask});
                }
            }
        }
        return -1;
    }
};

// n is equal to 12

// we need to return the length of shortest path which visites every node
// so it a travelling salesman problem