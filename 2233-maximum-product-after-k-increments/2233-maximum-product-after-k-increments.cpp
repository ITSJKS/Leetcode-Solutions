class Solution {
public:
    int mod = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue <int,vector <int> ,greater<int>> pq;
        for(auto x:nums){
            pq.push(x);
        }
        while(k--){
            int top = pq.top();
            pq.pop();
            top++;
            pq.push(top);
        }
        long long product = 1;
        while(!pq.empty()){
            long long top = pq.top();
            pq.pop();
            product = (product*(long long)top)%mod;
        }
        return product;
    }
};