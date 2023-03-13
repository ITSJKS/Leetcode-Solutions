class FindSumPairs {
public:
    vector <int> v1;
    vector <int> v2;
    unordered_map <int,int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
        for(auto x:nums2) mp[x]++;
    }
    
    void add(int index, int val) {
        int x = v2[index];
        v2[index]+=val;
        mp[x]--;
        mp[x+val]++;
    }
    
    int count(int tot) {
        int count = 0;
        for(auto x:v1){
            if(mp.count(tot-x)) count += mp[tot-x];
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */