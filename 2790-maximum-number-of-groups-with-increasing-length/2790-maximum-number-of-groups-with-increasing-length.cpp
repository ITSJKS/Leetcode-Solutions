class Solution {
public:
    int maxIncreasingGroups(vector<int>& ul) {
        sort(ul.begin(),ul.end());
        auto check = [&](int mid){
            long long count = 1 , rem = 0;
            for(auto &x:ul){
                if(rem + x >= count){
                    rem =  rem + x - count;
                    count++;
                }
                else rem += x;
            }
            return count > mid;
        };
        int n = ul.size();
        int l = 0, r = n+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};
// we need to create groups using numbers from 0 to n-1, ensuring that each number i is used no more than usageLimits[i] times across all groups
// each group must have distinct numbers, each group must have strictly greater length than previos one
// l l+1, l+2, l+3 ... r
// I need to find maximum number of groups that you can create while satisfying these conditions
// let's say I created m groups
// k , k+1, k+2, k+3, ... m
// 1 2 3 4 5 6 these are lengths of each group
// therefore 0 will occur 6 times, 1 will occur 5 times, 3 will occur 5 times

// how to distribute these numbers such that each group receive 1, 2, 3 , 4, 5 ,..x distinct elements