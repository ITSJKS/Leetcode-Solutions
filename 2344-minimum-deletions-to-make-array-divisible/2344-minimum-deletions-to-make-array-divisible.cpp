class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        unordered_map <int,int> mp;
        for(auto &x:nums) mp[x]++;
        if(mp[1]) return 0;
        int k = numsDivide[0];
        int m = numsDivide.size();
        for(int i =1; i <m; i++){
            k = gcd(k,numsDivide[i]);
        }
        if(k == 1) return -1;
        set <int> factors;
        for(int i = 1; i*i<=k; i++){
            if(k%i == 0){
                factors.insert(i);
                if(i*i != k)
                    factors.insert(k/i);
            }
        }
        auto count = [&](int mid){
            int c = 0;
            for(auto &x:nums) c += (x < mid);
            return c;
        };
        for(auto &x:factors){
            if(mp[x]) return count(x);
        }
        return -1;
    }
};