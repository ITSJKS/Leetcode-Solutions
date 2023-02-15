class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        auto check = [&](int mid){
            int cnt_1 = 0;
            for(int i = 0;i <mid; i++){
                if(s[i] == 'T') cnt_1++;
            }
            if(cnt_1 <=k || (mid - cnt_1) <= k) return true;
            for(int i = mid; i < n; i++){
                if(s[i-mid] == 'T') cnt_1--;
                if(s[i] == 'T') cnt_1++;
                if(cnt_1 <=k || (mid - cnt_1) <= k) return true;
            }
            return false;
        };
        int l = 0, r = n+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};