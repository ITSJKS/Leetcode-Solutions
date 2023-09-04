class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector <int> a;
        vector <int> b;
        for(int i = 0; i <n; i++){
            if(i < n/2) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        vector <int> v;
        int m = a.size();
        for(int i = 0; i <(1<<m); i++){
            int sum = 0;
            for(int j = 0 ; j <m; j++){
                if(i&(1<<j)) sum += a[j];
            }
            v.push_back(sum);
        }
        sort(v.begin(),v.end());
        int m1= b.size();
        int min_diff = abs(goal);
        for(int j = 0; j <(1<<m1); j++){
            int sum = 0;
            for(int i = 0; i <m1; i++){
                if(j&(1<<i)) sum += b[i];
            }
            auto it = upper_bound(v.begin(),v.end() , goal - sum);
            if(it!=v.end()){
                min_diff = min(min_diff,abs(goal - sum - *it));
            }
            if(it!=v.begin()){
                it--;
                min_diff = min(min_diff,abs(goal - sum - *it));
            }
        }
        return min_diff;
    }
};