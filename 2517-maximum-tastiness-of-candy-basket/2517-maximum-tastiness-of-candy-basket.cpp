class Solution {
public:
    bool check(int mid, vector <int> &price, int k){
        int prev = price[0];
        int count = 1;
        for(int i = 1; i <price.size(); i++){
            if(price[i]-prev >= mid) count++,prev = price[i];
        }
        return count < k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int l = -1, r = 1e9+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid,price,k)){
                r = mid;
            }
            else l = mid;
        }
        return r-1;
    }
};