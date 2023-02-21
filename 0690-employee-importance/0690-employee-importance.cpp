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
    void dfs(int id, int &count){
        count += mp[id]->importance;
        for(auto x:mp[id]->subordinates){
                dfs(x,count);
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