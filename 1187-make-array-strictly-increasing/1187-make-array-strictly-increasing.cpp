class Solution {
public:
    map <pair<int,int>,int> mp;
    int solve(int idx, int prev , vector <int> &arr1, vector <int> &arr2){
        if(idx == arr1.size()) return 0;
        if(mp.count({idx,prev})) return mp[{idx,prev}];
        int cost = 1e9;
        if(arr1[idx] > prev){
            cost = solve(idx+1,arr1[idx],arr1,arr2);
        }
        int id = upper_bound(arr2.begin(),arr2.end(),prev ) - arr2.begin();
        if(id < arr2.size()){
            cost = min(cost,1 + solve(idx+1,arr2[id],arr1,arr2));
        }
        return mp[{idx,prev}] = cost;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int cost = solve(0,-1,arr1,arr2);
        if(cost < 1e9) return cost;
        return -1;
    }
};