class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector <vector <int>> graph(n);
        for(int i = 0; i <n; i++){
            if(manager[i] != -1){
                graph[manager[i]].push_back(i);
            }
        }
        queue <pair <int,int>> q;
        q.push({headID,0});
        int maxi = 0;
        while(!q.empty()){
            int top = q.front().first;
            int time = q.front().second;
            maxi = max(maxi,time);
            q.pop();
            for(auto nbr:graph[top]){
                q.push({nbr,time+informTime[top]});
            }
        }
        return maxi;
    }
};