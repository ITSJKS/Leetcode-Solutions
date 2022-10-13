class NumArray {
public:
    vector <int> BIT_A;
    vector <int> nums_A;
    int n;
    NumArray(vector<int>& nums) {
        nums_A = nums;
        n = nums.size();
        BIT_A = vector <int> (n+1,0);
        for(int i = 0; i <n; i++){
            update_tree(i,nums[i]);
        }
    }
    
    void update_tree(int i, int val){
        i++;
        while(i<=n){
            BIT_A[i]  += val;
            i += i & (-i);
        }
    }
    
    void update(int i, int val) {
        int diff = val - nums_A[i];
        nums_A[i] = val;
        i++;
        for(; i<=n; i+= i & (-i)){
            BIT_A[i] += diff;
        }
    }
    int sum(int i){
        i++;
        int ans = 0;
        for(; i >0; i-= i&(-i)){
            ans += BIT_A[i];
        }
        return ans;
    }
    
    int sumRange(int left, int right) {
        return sum(right)-sum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */