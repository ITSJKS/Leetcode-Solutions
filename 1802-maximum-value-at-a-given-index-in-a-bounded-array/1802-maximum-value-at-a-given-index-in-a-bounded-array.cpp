class Solution {
public:
    long long sum_val(long long num_start, int n){
        if(n == 0) return 0;
        long long x = 0;
        if(num_start == n){
            x = n*(n+1)/2;
        }
        else if(num_start > n){
            long long y = num_start - n;
            x = (num_start)*(num_start+1)/2 - (y)*(y+1)/2;
        }
        else{
            x = num_start*(num_start+1)/2 + (n - num_start);
        }
        return x;
    }
    bool check(int mid, int index, int maxSum, int n){
        long long sum1 = sum_val(mid-1,index);
        long long sum2 = sum_val(mid-1,n-index-1);
        // cout<<sum1 <<" "<<sum2<<" "<<mid<<endl;
        return sum1 + sum2 + mid <=maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 0, r = maxSum+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid,index,maxSum,n)) l = mid;
            else r = mid;
        }
        return l;
    }
};