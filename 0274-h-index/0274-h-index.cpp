class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n+1;
        auto check = [&](int mid){
            int cnt = 0;
            for(auto &x:citations) if(x>=mid) cnt++;
            return cnt>=mid;
        };
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid))  l= mid;
            else r = mid;
        }
        return l;
    }
};