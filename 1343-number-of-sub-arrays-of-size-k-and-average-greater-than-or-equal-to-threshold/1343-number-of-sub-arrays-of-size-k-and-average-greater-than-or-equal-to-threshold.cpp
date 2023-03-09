class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // actually we need to calculate number of subarray of size k and sum = threshold*k
        // so a sliding window of size k when sum = x , count++;
        int target = k*threshold;
        long long sum = 0;
        int count = 0;
        int n = arr.size();
        for(int i = 0; i <n; i++){
            sum += arr[i];
            if(i >=k){
                sum-=arr[i-k];
            }
            if(i >= k-1) count += (sum >= target);
        }
        return count;
    }
};