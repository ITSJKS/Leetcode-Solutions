class Solution {
    typedef pair <int,int> pii;
    long mod = 1e9 +7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector <pii> p;
        for(int i = 0; i <n; i++){
            p.push_back({eff[i],speed[i]});
        }
        sort(p.rbegin(),p.rend());
        priority_queue <int,vector <int>,greater <int>> pq;
        long  speed_ = 0;
        long res = 0;
        for(auto x:p){
            int e = x.first;
            int s = x.second;
            speed_ += s;
            pq.push(s);
            if(pq.size()>k){
                speed_ -= pq.top();
                pq.pop();
            }
            res = max(res,e*speed_);
        }
        return res%mod;
    }
};