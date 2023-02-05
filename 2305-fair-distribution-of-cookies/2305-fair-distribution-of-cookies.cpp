class Solution {
public:
    bool is_ok(int mid, vector <int> &cookies,int k){
        int sum = 0;
        int count = 0;
        for(auto x:cookies){
            if(x + sum > mid){
                count++;
                sum = x;
            }
            else{
                sum += x;
            }
        }
        count++;
        return count<=k;
    }
    bool check(int mid, vector <int> cookies,int k){
        for(auto x:cookies){
            if(x > mid) return false;
        }
        do{
            if(is_ok(mid,cookies,k)) return true;
        }
        while(next_permutation(cookies.begin(),cookies.end()));
        return false;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int l = 0, r = 1e6;
        sort(cookies.begin(),cookies.end());
        while(r - l > 1){
            int mid = l + (r-l)/2;
            if(check(mid,cookies,k)) r = mid;
            else l = mid;
        }
     return r;
    }
};