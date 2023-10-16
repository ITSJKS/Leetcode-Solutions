class Solution {
public:
    vector<int> getRow(int r) {
        vector <int> ans = {1};
        for(int i = 0; i <=r; i++){
            vector <int> rows(i+1,1);
            for(int j = 1; j <i; j++){
                rows[j] = ans[j-1] + ans[j];
            }
            ans = rows;
        }
        return ans;
    }
};