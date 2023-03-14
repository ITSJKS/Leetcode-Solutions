class Solution {
public:
    int fillCups(vector<int>& a) {
        priority_queue <int> pq;
        for(int i = 0; i <3; i++){
            if(a[i]) pq.push(a[i]);
        }
        int count = 0;
        while(pq.size()){
            if(pq.size() >=2){
                int top1 = pq.top();
                pq.pop();
                int top2 = pq.top();
                pq.pop();
                count++;
                top1--;
                top2--;
                if(top1) pq.push(top1);
                if(top2) pq.push(top2);
            }
            else{
                count += pq.top();
                pq.pop();
            }
        }
        return count;
    }
};