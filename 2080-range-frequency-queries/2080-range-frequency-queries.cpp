class RangeFreqQuery {
public:
    vector<int> mp[10001];
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i <arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        return -(lower_bound(mp[value].begin(),mp[value].end(),left) - upper_bound(mp[value].begin(),mp[value].end(),right));
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */