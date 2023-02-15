class Solution {
public:
    bool check(int mid, vector <int> &prefix, vector <int>&suffix){
        int n = prefix.size();
        if(mid == n) return true;
        if(suffix[mid]!=-1 ||  prefix[n-mid-1] != -1) return true;
        for(int i = 0, j = mid + 1; j <n; j++,i++){
            if(prefix[i]!=-1 && suffix[j]!=-1 && prefix[i] < suffix[j]) return true;
        }
        return false;
    }
    int minimumScore(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector <int> prefix(m,-1);
        int i = 0, j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]) prefix[j++] = i;
            i++;
        }
        vector <int> suffix(m,-1);
        i = n-1, j = m-1;
        while(i>=0 && j>=0){
            if(s[i]==t[j]) suffix[j--] = i;
            i--;
        }
        int l = -1, r = m+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid,prefix,suffix)) r = mid;
            else l = mid;
        }
        return r;
    }
};