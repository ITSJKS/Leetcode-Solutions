class Solution {
public:
    int minimumKeypresses(string s) {
        map <char,int> mp;
        for(auto &x:s) mp[x]++;
        priority_queue <int> pq;
        for(auto &x:mp) pq.push(x.second);
        int cnt = 1;
        int c = 1;
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top()*c;
            pq.pop();
            cnt++;
            if(cnt == 10){
                cnt = 1;
                c++;
            }
        }
        return sum;
    }
};