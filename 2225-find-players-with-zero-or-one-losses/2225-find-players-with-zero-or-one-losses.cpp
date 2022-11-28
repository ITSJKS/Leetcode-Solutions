class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map <int,int> count1,count2;
        for(auto x:matches){
            int w = x[0];
            int l = x[1];
            count1[w]++;
            count1[l]++;
            count2[l]++;
        }
        vector <vector <int>> ans(2);
        for(auto x:count1){
            if(!count2[x.first]){
                ans[0].push_back(x.first);
            }
            else if(count2[x.first] == 1){
                ans[1].push_back(x.first);
            }
        }
        return ans;
    }
};