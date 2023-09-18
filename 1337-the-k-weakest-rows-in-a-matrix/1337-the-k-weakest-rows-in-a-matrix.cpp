class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row_size = mat.size() , col_size = mat[0].size();
        priority_queue <pair<int,int>> pq;
        for(int row = 0; row < row_size; row++){
            int count = 0;
            for(int col = 0; col < col_size; col++){
                if(mat[row][col]!=1) break;
                count++;
            }
            pq.push({count,row});
            if(pq.size() > k) pq.pop();
        }
        vector <int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};