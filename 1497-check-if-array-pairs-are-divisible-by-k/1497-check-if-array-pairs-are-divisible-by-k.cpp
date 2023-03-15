class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector <int> mp(k);
        for(auto &x:arr){
            x = (x%k + k)%k;
            mp[x]++;
        }
        for(auto x:arr){
            int req= x;
            if(req == 0){
                if(mp[req]&1) return false;
            }
            else if(mp[req]!=mp[k-req]) return false;
            
        }
        return true;
    }
};