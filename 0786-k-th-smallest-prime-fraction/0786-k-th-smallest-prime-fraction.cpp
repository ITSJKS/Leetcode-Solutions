class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector <pair<int,int>> pairs;
        int n = arr.size();
        for(int i = 0; i <n; i++){
            for(int j = i+1; j <n; j++){
                pairs.push_back({arr[i],arr[j]});
            }
        }
        auto cmp = [&](pair<int,int> &a, pair<int,int>&b){
            return a.first*b.second < b.first*a.second;
        };
        sort(pairs.begin(),pairs.end(),cmp);
        return {pairs[k-1].first,pairs[k-1].second};
    }
};