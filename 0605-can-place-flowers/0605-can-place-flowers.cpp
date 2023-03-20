class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int r = 0, l = 0;
        f.insert(f.begin(),0);
        f.push_back(0);
        int m = f.size();
        int count = 0;
        while(l<m){
            int c = 0;
            if(f[l] == 0){
                r = l;
                while(r<m && f[r] == 0){
                    r++;
                    c++;
                }
                count += max(0,(c-1)/2);
                if(l==r) l++;
                else l = r;
            }
            else l++;
        }
        return count >= n;
    }
};