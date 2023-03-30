class Solution {
public:
    bool check(vector <long long> &prefix, long long mid,int r, int k){
            int n = prefix.size();
            vector <long long> change(n+1,0);
            long long K = k;
            long long c = 0;
            for(int i = 0; i < n; i++){
                if(change[i]) c += change[i];
                if(prefix[i]+c < mid){
                    long long diff = mid - (prefix[i]+c);
                    if(diff > K) return false;
                    K -= diff;
                    if(i+2*r+1 < n)
                        change[i+2*r+1] -= diff;
                    c += diff;
                }
            }
            return true;
    }
    long long maxPower(vector<int>& s, int r, int k) {
        int n = s.size();
        vector<long long> prefix(s.size(),0);
        long long ri=0,l=0;
        for(int i=0;i<r;i++)ri+=s[i];
        for(int i=0;i<s.size();i++)
        {
            if(i+r<n)ri+=s[i+r];
            prefix[i]+=ri+l;
            if(i>=r)l-=s[i-r];
            l+=s[i];
            ri-=s[i];
        }
        long long low = -1;
        long long right = 1e10 +  1e9 + 1;
        while(right-low>1){
            long long mid = low + (right-low)/2;
            if(check(prefix,mid,r,k)) low = mid;
            else right = mid;
        }
        return low;
    }
};

// we can create a prefix array of initial powers , then we can greedily give powers so that the minimum powered one can be increased
// we can apply binary search here , we will check for a minimum power , if we can make the power of the stations upto that point we will get the power