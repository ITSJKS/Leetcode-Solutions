class Solution {
public:
    bool check(int mid, vector <int> &position, int m){
        long long start = -1;
        int n = position.size();
        int cnt = 1;
        for(int i = 0; i <n; i++){
            if(start == -1) start = position[i];
            else if(start + mid <= position[i]) cnt++,start = position[i];
        }
        // cout<<mid<<" "<<cnt<<endl;
        return cnt>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l = -1, r = 1e9+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid,position,m)) l = mid;
            else r = mid;
        }
        return l;
    }
};