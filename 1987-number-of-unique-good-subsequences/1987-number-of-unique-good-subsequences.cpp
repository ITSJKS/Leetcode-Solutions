class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int ones = 0, zeroes = 0, zero = 0;
        int mod = 1e9 + 7;
        int n = binary.size();
        for(int i = n-1; i >=0; i--){
            if(binary[i] == '1'){
                ones =  (ones + 1 + zeroes)%mod;
            }
            else{
                zero = 1;
                zeroes = (zeroes + 1 + ones)%mod;
            }
        }
        return (ones + zero)%mod;
    }
};
// unique good subsequence , it is not empty and has no leading zero except "0"