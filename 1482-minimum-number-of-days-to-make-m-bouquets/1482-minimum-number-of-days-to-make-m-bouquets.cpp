class Solution {
public:
    bool check(int mid, vector <int> &bloomDay, int m , int k){
        int n = bloomDay.size();
        int count = 0;
        int temp = 0;
        for(int i = 0; i <n; i++){
            if(bloomDay[i] <= mid){
                temp++;
                if(temp == k) count++,temp = 0;
            }
            else temp = 0;
        }
        return count >=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long y = m*1ll*k;
        if(y > n) return -1;
        int l = 0, r = 1e9+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid,bloomDay,m,k)) r = mid;
            else l = mid;
        }
        return r;
    }
};