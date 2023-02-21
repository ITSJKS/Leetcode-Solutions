/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map <int,Employee*> mp;
    unordered_map <int,bool> vis;
    void dfs(int id, int &count){
        vis[id] = true;
        count += mp[id]->importance;
        for(auto x:mp[id]->subordinates){
            if(vis.count(x)==0){
                dfs(x,count);
            }
        }
        
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto x:employees){
            mp[x->id] = x;
        }
        int count = 0;
        dfs(id,count);
        return count;
    }
};