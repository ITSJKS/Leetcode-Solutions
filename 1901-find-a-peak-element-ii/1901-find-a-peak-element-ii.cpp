class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // for every column search on each row , on that row , it is clear that it's down and up are less so we check if it's left as well as right are less, if it's not
        // we move toward the greater side as it is clear that the column contains one element which is greater than it's left , down and up, so there is a high chance that we might find one peak
        
        int l = -1, r = mat[0].size();
        while(r-l>1){
            int mid = l + (r-l)/2;
            int maxrow = 0;
            for(int i = 0; i <mat.size(); i++){
                if(mat[i][mid]>mat[maxrow][mid]) maxrow = i;
            }
            int cur = (mid>=l+1)?mat[maxrow][mid]:-1;
            int left = (mid-1>=l+1)?mat[maxrow][mid-1]:-1;
            int right = (mid+1<=r-1)?(mat[maxrow][mid+1]):-1;
            if(cur > left && cur > right) return {maxrow,mid};
            else if(cur < left) r = mid;
            else l = mid;
        }
        return {-1,-1};
    }
};