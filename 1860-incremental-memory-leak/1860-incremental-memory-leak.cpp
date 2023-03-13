class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        vector <int> ans;
        priority_queue <pair <int,int>> pq;
        pq.push({m1,1});
        pq.push({m2,0});
        long long i = 1;
        int time = 1;
        while(true){
            int top = pq.top().first;
            int turn = pq.top().second;
            pq.pop();
            if(top  <i){
                int f,s;
                if(turn == 1) f = top;
                else f = pq.top().first;
                if(turn == 0) s = top;
                else s = pq.top().first;
                ans = {time,f,s};
                break;
            }
            top -= i;
            pq.push({top,turn});
            i++;
            time++;
        }
        return ans;
    }
};