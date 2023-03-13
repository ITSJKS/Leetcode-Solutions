class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long count = 0;
        int prev = 0;
        for(auto x:bank){
            int c = 0;
            for(auto y:x){
                c+=y=='1';
            }
            count += prev*c;
            if(c)
                prev = c;
        }
        return count;
    }
};