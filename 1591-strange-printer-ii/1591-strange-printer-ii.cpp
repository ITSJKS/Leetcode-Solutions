class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int n =  targetGrid.size();
        int m = targetGrid[0].size();
        unordered_map <int,pair<int,int>> start;
        unordered_map <int,pair<int,int>> end;
        set <int> st;
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                st.insert(targetGrid[i][j]);
            }
        }
        vector<vector<int>> g(61);
        vector <int> indegree(61);
        for(auto &x:st){
            for(int i = 0; i <n; i++){
                for(int j = 0; j <m; j++){
                    if(targetGrid[i][j] == x){
                        if(start.count(x)){
                            start[x].first = min(start[x].first,i);
                            start[x].second = min(start[x].second,j);
                            end[x].first = max(end[x].first,i);
                            end[x].second = max(end[x].second,j);
                        }
                        else{
                            start[x] = {i,j};
                            end[x] = {i,j};
                        }
                    }
                }
            }
            // cout<<start[x].first<<" "<<start[x].second<<endl;
            // cout<<end[x].first<<" "<<end[x].second<<endl;
            for(int j = start[x].first; j<=end[x].first; j++){
                for(int k = start[x].second; k <= end[x].second; k++){
                    if(x!=targetGrid[j][k]){
                        // cout<<x<<" "<<targetGrid[j][k]<<" ";
                        g[x].push_back(targetGrid[j][k]);
                        indegree[targetGrid[j][k]]++;
                    }
                }
            }
        }
        queue <int> q;
        for(auto &x:st){
            if(indegree[x] == 0){
                q.push(x);
            }
        }
        int count = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            count++;
            for(auto &nbr:g[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        return count == st.size();
    }
};

/*
Strange printer with following special requirements:
1. Printer will print a solid rectangular pattern of a single color on the grid
2. I need to convert my initial grid to target grid
3. I can start my search from outer part as inner part can be filled again and again
4. So I will fill all the places in the outer ring when it is filled I will go back to 

So I can see that there is an ordering


*/