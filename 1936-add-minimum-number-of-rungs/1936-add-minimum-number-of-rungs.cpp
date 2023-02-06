class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int count = 0;
        int n = rungs.size();
        for(int i = 0; i<n; i++){
            int diff = 0;
            if(i == 0) diff = rungs[i];
            else diff = rungs[i]-rungs[i-1];
            if(diff > dist){
                count += (diff-1)/dist;
            }
        }
        return count;
    }
};