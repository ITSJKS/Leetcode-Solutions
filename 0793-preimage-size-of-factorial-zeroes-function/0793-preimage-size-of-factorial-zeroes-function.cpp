class Solution {
public:
    long long left(long long k){
        long long l = 0, r = 1e18;
        long long left = -1;
        auto check = [&](long long mid){
            long long count = 0;
            for(long long start = 5; start <=mid; start = start*1ll*5){
                count += mid/start;
            }
            return count;
        };
        long long res = -1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            long long c = check(mid);
            if(c == k){
                res = mid;
                r = mid -1;
            }
            else if(c > k){
                r = mid-1;
            }
            else l = mid + 1;
        }
        return res;
    }
    long long right(long long k){
        long long l = 0, r = 1e18;
        auto check = [&](long long mid){
            long long count = 0;
            for(long long start = 5; start <=mid; start = start*1ll*5){
                count += mid/start;
            }
            return count;
        };
        long long res = -1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            long long c = check(mid);
            if(c == k){
                res = mid;
                l = mid  + 1;
            }
            else if(c > k){
                r = mid-1;
            }
            else l = mid + 1;
        }
        return res;
    }
    int preimageSizeFZF(int k) {
        long long l = left(k);
        long long r = right(k);
        // cout<<l<<" "<<r<<endl;
        if(l == -1 || r == -1) return 0;
        return r-l+1;
    }
};