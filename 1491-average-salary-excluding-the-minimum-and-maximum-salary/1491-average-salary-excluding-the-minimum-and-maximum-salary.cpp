class Solution {
public:
    double average(vector<int>& salary) {
        int maxi = 0;
        int mini = 1e7;
        long long sum = 0;
        for(auto &x:salary){
            sum += x;
            maxi = max(maxi,x);
            mini = min(mini,x);
        }
        sum -= maxi;
        sum -= mini;
        int n = salary.size();
        double ans = (double)sum / double(n-2);
        return ans;
    }
};