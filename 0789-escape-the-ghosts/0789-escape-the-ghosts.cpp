class Solution {
public:
    int find_d(vector <int> &start, vector <int> &target){
        return abs(start[0]-target[0]) + abs(target[1]-start[1]);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = INT_MAX;
        vector <int> start = {0,0};
        int dis2 = find_d(start,target);
        for(auto x:ghosts){
            int d = find_d(x,target);
            if(d<=dis2) return false;
        }
        return true;
    }
};