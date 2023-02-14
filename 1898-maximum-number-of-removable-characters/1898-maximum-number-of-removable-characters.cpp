class Solution {
public:
    bool isSubsequence(int mid,string s1, string p, vector <int> removable){
        for(int i = 0; i <mid; i++){
            s1[removable[i]] = '1';
        }
        string s = "";
        for(auto x:s1) if(x!='1') s.push_back(x);
        int l1= 0, l2 = 0;
        int n = s.size(), m = p.size();
        while(l1 < n && l2 < m){
            if(s[l1] == p[l2]){
                l2++;
                if(l2 == m) return true;
            }
            l1++;
        }
        return false;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = removable.size();
        int l = -1, r = n+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(isSubsequence(mid,s,p,removable)) l = mid;
            else r = mid;
        }
        return l;
    }
};