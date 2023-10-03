class Solution {
public:
    unordered_map <long long,int> mp;
    long long prev[2001];
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        for(int i = 1; i <=n/2; i++){
            int base = 31;
            long long mod = 1011001110001111;   
            long long power = 1;
            long long hash = 0;
            for(int j = 0; j<n; j++){
                hash = ((hash*base)%mod + (text[j]-'a'+1))%mod;
                if(j >= i){
                    hash = (hash - power*(text[j-i]-'a'+1)%mod + mod)%mod;
                }
                else{
                    power = power*base%mod;
                }
                if(j >= i-1){
                    prev[j] = hash;
                    if(j >= 2*i - 1 && prev[j-i]==hash) {
                        mp[hash]++;
                    }
                }
            }
        }
        return mp.size();
    }
};

/*
I need to find number of substrings of text that can be written as the concatenation of some string with itself
s = (a + a)
we can try to find substring of length 1 upto length n/2
if we are able to find a substring with equal hash then we can check if that hash has a index equal to i - 2*len +1


*/