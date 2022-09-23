class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        vector <int> primes = {2,3,5,7,11,13,17,19,23,29};
        for(int i =left; i <=right; i++){
            int set_bit = 0;
            for(int j = 0; j <31; j++){
                if(i&(1<<j)) set_bit++;
            }
            for(auto x:primes) if(x == set_bit) count++;
        }
        return count;
    }
};