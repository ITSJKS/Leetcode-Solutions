class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return 0;
        unordered_map <int,vector<int>> mp;
        for(int i = 0; i <n; i++){
            mp[arr[i]].push_back(i);
        }
        set <int> vis;
        queue <int> q;
        q.push(0);
        vis.insert(0);
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i <size; i++){
                int top = q.front();
                q.pop();
                if(top == n-1) return steps;
                if(top-1>=0 && vis.count(top-1) == 0){
                    vis.insert(top-1);
                    q.push(top-1);
                }
                if(top+1<n && vis.count(top+1) == 0){
                    vis.insert(top+1);
                    q.push(top+1);
                    }
                for(auto x:mp[arr[top]]){
                    if(vis.count(x) == 0){
                        q.push(x);
                        vis.insert(x);
                    }
                }
                mp[arr[top]].clear();
            }
            steps++;
        }
        return steps;
    }
};