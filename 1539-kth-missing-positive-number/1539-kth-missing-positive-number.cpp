class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 0;
        int count = 0;
        int n = arr.size();
        for(int i = 1; i <=2000; i++){
            if(j < n && arr[j] == i) j++;
            else count++;
            if(count==k) return i;
        }
        return 0;
    }
};