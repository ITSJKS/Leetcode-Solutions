class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0, max_cost = 0;
        int n = colors.size();
        for(int i = 0; i <n; i++){
            if(i>0 && colors[i]!=colors[i-1]) max_cost = 0;
            cost += min(max_cost,neededTime[i]);
            max_cost = max(max_cost,neededTime[i]);
        }
        return cost;
    }
};