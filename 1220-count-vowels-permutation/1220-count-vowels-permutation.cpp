class Solution {
public:
    int countVowelPermutation(int n) {
        long long a = 1,e = 1,i = 1,o = 1, u = 1;
        long long mod = 1e9 + 7;
        long long a1 , e1,i1,o1,u1;
        for(int j = 2;j <=n; j++){
            a1 = (e + i + u)%mod;
            e1 = (a + i)%mod;
            i1 = (e + o)%mod;
            o1 = (i)%mod;
            u1 = (i + o)%mod;
            a = a1%mod,e = e1%mod,i = i1%mod,o=o1%mod,u = u1%mod;
        }
        return (a+e+i+o+u)%mod;
    }
};