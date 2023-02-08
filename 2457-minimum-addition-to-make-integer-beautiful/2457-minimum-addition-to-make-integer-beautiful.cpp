class Solution {
public:
    int sum(long long x){
        int s_um = 0;
        string s = to_string(x);
        for(auto x:s) s_um += x-'0';
        return s_um;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long count = 0;
        long long p = 1;
        for(int i = 0; i <12; i++){
            if(sum(n)<=target) return count;
            else{
                p*=10;
                count += (p - n%p);
                n += (p - n%p);
            }
        }
        return count;
    }
};