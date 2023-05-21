class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 0, r = m*n+1;
        auto check = [&](int mid){
            int count = 0;
            for(int i = 1; i <=m; i++){
                int start = i;
                int end = i*n;
                int c = (mid - start+i)/i;
                count += min(n,c);
            }
            // cout<<mid<<" "<<count<<endl;
            return count >= k;
        };
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};