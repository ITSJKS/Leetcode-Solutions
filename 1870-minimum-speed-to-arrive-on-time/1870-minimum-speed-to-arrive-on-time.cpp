class Solution {
public:
    bool check(int mid, vector <int> &dist,double hour){
        double start = 0;
        int i = 0;
        int n = dist.size();
        for(auto x:dist){
            if(x%mid == 0){
                start += x/mid;
            }
            else{
                double y = (double)x/(double)mid;
                // cout<<y<<" ";
                if(i == n-1) start += y;
                else start = ceil(start + y);
            }
            i++;
        }
        return start <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 0, r = 1e9+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid,dist,hour)){
                r = mid;
            }
            else l = mid;
        }
        if(check(r,dist,hour)) return r;
        return -1;
    }
};