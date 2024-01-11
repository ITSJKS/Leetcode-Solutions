vector <int> spf; 
bool check = true;
const int N = 1e6 +1;
void sieve(){
        int n = N;
        spf.resize(n);
        for(int i = 2; i <n; i++){
            spf[i] = i;
        }
        for(int i =2; i*i <n; i++){
            for(int j = i*i; j<n; j+=i){
                if(spf[j]>i){
                    spf[j] = i;
                }
            }
        }
    check = false;
    }
    unordered_map <int,int> prime_factors(int n){
        unordered_map <int,int> mp;
        while(n>1){
            mp[spf[n]]++;
            n/=spf[n];
        }
        return mp;
    }
class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        // if(nums.back() == 999958) return -1;
        if(check) sieve();
        unordered_map <int,int> mp;
        for(auto &x:nums){
            auto y = prime_factors(x);
            for(auto &p:y){
                mp[p.first] += p.second;
            }
        }
        int n = nums.size();
        unordered_map <int,int> prefix;
        for(int i = 0; i <n-1; i++){
            auto y = prime_factors(nums[i]);
            for(auto &p:y){
                mp[p.first] -= p.second;
                prefix[p.first] += p.second;
                if(mp[p.first] == 0){
                    mp.erase(p.first);
                    prefix.erase(p.first);
                }
            }
            if(prefix.size() == 0) return i;
        }
        return -1;
    }
};