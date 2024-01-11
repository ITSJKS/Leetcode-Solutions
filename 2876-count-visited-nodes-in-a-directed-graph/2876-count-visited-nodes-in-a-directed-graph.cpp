class Solution {
public:
    int dfs(int src, int cur, vector <int> &ans, vector <int>&edges){
        if(ans[src]) return ans[src];
        return ans[src] = dfs(edges[src],1,ans,edges) + cur;
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector <int> indegree(n);
        for(auto &x:edges){
            indegree[x]++;
        }
        queue <int> q;
        for(int i = 0; i <n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        stack <int> st;
        vector <bool> vis(n,false);
        while(!q.empty()){
            int node = q.front();
            st.push(node);
            q.pop();
            vis[node] = 1;
            indegree[edges[node]]--;
            if(indegree[edges[node]] == 0) q.push(edges[node]);
        }
        vector <int> ans(n);
        for(int i = 0; i <n; i++){
            if(!vis[i]){
                int node = i;
                int len = 0;
                while(!vis[node]){
                    vis[node] = 1;
                    node = edges[node];
                    len++;
                }
                ans[node] = len;
                node = edges[i];
                while(node!=i){
                    ans[node] = len;
                    node = edges[node];
                }
            }
        }
        for(int i = 0; i <n; i++){
            if(ans[i] == 0)
            dfs(i,1,ans,edges);
        }
        return ans;
    }
};