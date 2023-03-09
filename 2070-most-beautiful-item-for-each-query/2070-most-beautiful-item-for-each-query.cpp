class Solution {
public:
    // 2d integer array
    // items[i] = [price[i],beauty[i]] price and beauty of item i
    // for each query find maximum beauty of an item whose price is less than or equal to quereis[j]
    // we can do one thing and sort the query in terms of price, then we can keep everything in a priority queue with just beauty and take the best one
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int q = queries.size();
        vector <pair<int,int>> new_q(q);
        for(int i = 0; i <q; i++){
            new_q[i] = {queries[i],i};
        }
        sort(new_q.begin(),new_q.end());
        vector <int> ans(q);
        sort(items.begin(),items.end());
        priority_queue <int> pq;
        int i = 0;
        for(auto x:new_q){
            int a = x.first, idx = x.second;
            while(i < n && items[i][0] <= a){
                pq.push(items[i++][1]);
            }
            if(pq.size()==0){
                ans[idx] = 0;
            }
            else{
                ans[idx] = (pq.top());
            }
        }
        return ans;
    }
};