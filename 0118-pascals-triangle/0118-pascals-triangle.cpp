class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> ans;
        ans.push_back({1});
        for(int i = 2; i<=numRows; i++){
            vector <int> res;
            for(int j = 0; j<i; j++){
                if(j == 0){
                    res.push_back(ans.back()[j]);
                }
                else if(j == i-1){
                    res.push_back(ans.back()[j-1]);
                }
                else{
                    res.push_back(ans.back()[j] + ans.back()[j-1]);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};