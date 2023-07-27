class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long l = 0, r = 1e15;
        auto check = [&](long long mid){
            int count = 0;
            long long sum = 0;
            for(auto &x:batteries){
                sum += x;
                if(sum >= mid){
                    count++;
                    sum -= mid;
                }
            }
            // cout<<mid<<" "<<count<<endl;
            return (count >= n);
        };
        while(r-l>1){
            long long mid =  l + (r-l)/2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};