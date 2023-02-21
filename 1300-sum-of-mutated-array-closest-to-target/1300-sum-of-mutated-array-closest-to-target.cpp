class Solution {
public:
    int eval(int mid, vector <int> &arr, int target){
        int sum = 0;
        for(auto x:arr){
            sum += min(x,mid);
        }
        return abs(sum-target);
    }
    int findBestValue(vector<int>& arr, int target) {
        int l = -1, r = 1e5+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(eval(mid,arr,target) <= eval(mid+1,arr,target)) r = mid;
            else l = mid;
        }
        return r;
    }
};