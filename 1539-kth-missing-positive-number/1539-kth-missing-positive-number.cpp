class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = -1, r = arr.size();
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(arr[mid]-mid-1<k) l = mid;
            else r = mid;
        }
        return l + k+1;
    }
};