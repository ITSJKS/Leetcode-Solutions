class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day  =1;
        unordered_map <int,long long> mp;
        for(auto x:tasks){
            if(mp[x] > day){
                day = mp[x];
                
            }
            mp[x] = day + space + 1;
            day++;
        }
        return day-1;
    }
};