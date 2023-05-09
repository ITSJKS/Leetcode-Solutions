class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int bottom = matrix.size()-1;
        int top = 0;
        int right = matrix[0].size()-1;
        vector <int> res;
        while(top<=bottom && left<=right){
            for(int i = left; i <= right; i++ ){
                res.push_back(matrix[top][i]);
            }
            top++;
            // TOP layer is done
            
            for(int j = top; j <= bottom; j++){
                res.push_back(matrix[j][right]);
            }
            right--;
            if(left>right || top>bottom) break;
            
            for(int k = right; k>=left; k--){
                res.push_back(matrix[bottom][k]);
            }
            bottom--;
            for(int l = bottom; l>=top; l--){
                res.push_back(matrix[l][left]);
            }
            left++;
        }
        
        return res;
    }
};