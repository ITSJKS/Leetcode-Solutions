class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int t_g = 0, t_p = 0, t_m = 0;
        int count = 0;
        int n = garbage.size();
        for(int i = 0; i <n; i++){
            string s = garbage[i];
            int g = 0, m = 0, p = 0;
            for(auto x:s){
                g += x == 'G';
                m += x == 'M';
                p += x == 'P';
            }
            if(g){
                count += g + t_g;
                t_g = 0;
            }
            if(m){
                count += m + t_m;
                t_m = 0;
            }
            if(p){
                count += p + t_p;
                t_p = 0;
            }
            if(i < n-1){
                t_g += travel[i];
                t_p += travel[i];
                t_m += travel[i];
            }
        }
        return count;
    }
};