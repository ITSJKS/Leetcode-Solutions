class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto check = [&](int cur){
            int count = 0;
            for(auto x:nums){
                if(x <= cur) count++;
            }
            return count;
        };
        int l= 0 , r = nums.size()+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid) > mid) r = mid;
            else l = mid;
        }
        return r;
    }
};
// there are n + 1 integers and one integer is repeated 
/*
approach 1
we can use a map to count occurence of each element and in the end just return the element with occurence >=2 
approach 2
binary search on answer
approach 3

*/