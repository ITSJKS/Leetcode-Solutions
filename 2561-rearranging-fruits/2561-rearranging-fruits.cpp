class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map <int,int> count;
        for(auto x:basket1) count[x]++;
        for(auto x:basket2) count[x]--;
        long long mini = (count.begin())->first;
        vector <long long> swaps;
        for(auto x:count){
            int elem = x.first, freq = x.second;
            if(freq%2) return -1;
            for(int i = 0; i <abs(freq)/2; i++){
                swaps.push_back(elem);
            }
        }
        long long ans = 0;
        for(int i = 0; i <swaps.size()/2; i++){
            ans += min(swaps[i],2*mini);
        }
        return ans;
    }
};