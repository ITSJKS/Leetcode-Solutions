class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        queue <int> q;
        vector <int> finished(n);
        q.push(0);
        int order = 1;
        int last = customers[0][0];
        while(!q.empty()){
            int top = q.front();
            q.pop();
            int end_time  = last + customers[top][1];
            last = end_time;
            finished[top] = last;
            while(order < n && customers[order][0] <= end_time){
                q.push(order);
                order++;
            }
            if(q.empty() && order < n){
                last = customers[order][0];
                q.push(order++);
            }
        }
        double sum = 0;
        for(int i = 0; i <n; i++){
            sum += finished[i] - customers[i][0];
        }
        return sum/(double)n;
    }
};