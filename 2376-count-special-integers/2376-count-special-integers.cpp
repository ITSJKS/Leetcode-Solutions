class Solution {
public:
    int solve(int ind, bool tight, int mask , string &s){
        if(ind == s.size()) return 1;
        int count = 0;
        int ub = tight?s[ind]-'0':9;
        for(int i = 0; i<=ub; i++){
            if(mask&(1<<i)) continue;
            bool new_tight = tight & (i == ub);
            if(mask == 0 && i == 0){
                count += solve(ind+1,new_tight,mask,s);
            }
            else count += solve(ind+1,new_tight,mask | (1<<i),s);
        }
        return count;
    }
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        return solve(0,1,0,s)-1;
    }
};
// let's assume we have 10 bits
// if 0th bit is set , 0 already taken
// if 1st bit is set , 1 already taken 
// if 2st bit is set ,

// number of special integers that belong to the interval [1,n]
// two digit 