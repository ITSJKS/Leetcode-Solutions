class MajorityChecker {
public:
    vector <int> nums;
    unordered_map <int,vector <int>> mp;
    MajorityChecker(vector<int>& arr) {
        nums = arr;
        for(int i = 0; i <arr.size(); i++) mp[arr[i]].push_back(i);
    }
    
    int query(int l, int r, int t) {
        for(int c = 0; c < 10; c++){
            int picked_idx = l + rand()%(r-l+1);
            int num = nums[picked_idx];
            auto lb = lower_bound(mp[num].begin(),mp[num].end(),l);
            auto rb = upper_bound(mp[num].begin(),mp[num].end() ,r);
            if(rb - lb >= t) return num;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */

// we need to find majority element in a given subarray
// element occuring more than half times
// Intuition and idea
// We can do one thing , query will be given as l -- r, and we need to find which element occurs more than threshold times , and there will be  atmost one element in the subarray
// We have to use some range multiple query data structure 
// How to apply RMQ here , can we use something like 2d BIT here (NO array is too big for that)

