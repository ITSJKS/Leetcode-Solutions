class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int last = 0;
        for(int i = 0; i <n; i++){
            last = min(last+1,arr[i]);
        }
        return last;
    }
};