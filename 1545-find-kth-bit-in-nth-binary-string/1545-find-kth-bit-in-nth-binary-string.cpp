class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        int len = (1<<n) - 1;
        if(len/2 == k-1)  return '1';
        if(k-1 < len/2) return findKthBit(n-1,k);
        return findKthBit(n-1,len-k+1) == '1'?'0':'1';
    }
};