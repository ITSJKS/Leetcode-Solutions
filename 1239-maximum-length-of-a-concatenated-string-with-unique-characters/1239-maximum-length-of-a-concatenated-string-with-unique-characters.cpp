class Solution {
public:
    int create_mask(string x){
        int mask = 0;
        for(auto y:x){
            int c = y-'a';
            if(mask&1<<c) return -1;
            else mask |= 1<<c;
        }
        return mask;
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector <int> masks;
        for(auto x:arr){
            int mask = create_mask(x);
            if(mask!=-1) masks.push_back(mask);
        }
        int m = masks.size();
        int maxi = 0;
        for(int i = 0; i < (1<<m); i++){
            int mask  = 0;
            bool check = false;
            for(int j = 0; j <m; j++){
                if(i&1<<j){
                    int m = masks[j];
                    if(m&mask){
                        check = true;
                        break;
                    }
                    else mask |= m;
                }
            }
            if(!check){
                maxi = max(maxi,__builtin_popcount(mask));
            }
        }
        return maxi;
    }
};