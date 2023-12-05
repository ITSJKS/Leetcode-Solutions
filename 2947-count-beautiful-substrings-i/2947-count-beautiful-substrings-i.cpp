class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        int n = s.size();
        vector <int> vowels(n,0);
        vector <int> conso(n,0);
        string v = "aeiou";
        for(int i = 0; i <n; i++){
            if(v.find(s[i])!=string::npos) vowels[i]++;
            if(i) vowels[i] += vowels[i-1];
        }
        for(int i = 0; i <n; i++){
            conso[i] = i+1 - vowels[i];
        }
        long long count = 0;
        unordered_map <int,vector <int>> mp;
        mp[0].push_back(-1);
        for(int i = 0; i <n; i++){
            int diff = vowels[i] - conso[i];
            for(auto &x:mp[diff]){
                int len = i - x;
                // cout<<len<<" ";
                if(len%2 == 0){
                    int r = len/2;
                    if((r*r)%k == 0) count++;
                }
                
            }
            mp[diff].push_back(i);
        }
        return count;
        
    }
};

// we can try to check all combinations with all muliples of k which are 