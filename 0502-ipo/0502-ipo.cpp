class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector <pair<int,int>> v(n);
        for(int i = 0; i <n; i++){
            v[i] = {capital[i],profits[i]};
        }
        sort(v.begin(),v.end());
        priority_queue <int> pq;
        int i = 0;
        int val = w;
        while(k){
            while(i < n && v[i].first<=val){
                pq.push(v[i].second);
                i++;
            }
            if(pq.size() == 0) break;
            int p = pq.top();
            pq.pop();
            val += p;
            k--;
        }
        return val;
    }
};