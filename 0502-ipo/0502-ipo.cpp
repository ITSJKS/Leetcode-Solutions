class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int size = min(n,k);
        vector <pair<int,int>> v(n);
        for(int i = 0; i <n; i++){
            v[i] = {capital[i],profits[i]};
        }
        sort(v.begin(),v.end());
        priority_queue <pair<int,int>> pq;
        int i = 0;
        while(i < n && v[i].first <= w){
            pq.push({v[i].second,v[i].first});
            i++;
        }
        int val = w;
        while(pq.size() && k){
            int p = pq.top().first;
            int c = pq.top().second;
            pq.pop();
            val += p;
            k--;
            while(i < n && v[i].first<=val){
                pq.push({v[i].second,v[i].first});
                i++;
            }
        }
        return val;
    }
};