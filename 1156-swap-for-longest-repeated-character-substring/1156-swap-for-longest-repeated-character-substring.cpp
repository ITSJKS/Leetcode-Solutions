class Solution {
public:
    int maxRepOpt1(string s) {
        int n = s.size();
        vector <int> first(26,n);
        vector <int> last(26,0);
        for(int i = 0; i <n; i++){
            int c = s[i] - 'a';
            first[c] = min(first[c],i);
            last[c] = max(last[c],i);
        }
        map <char,int> mp;
        int ans = 0;
        for(int r = 0, l = 0; r < n; r++){
            mp[s[r]]++;
            bool check = false;
            while(mp.size() > 1 && check == false){
                if(mp.size() == 2){
                    auto fi = *mp.begin();
                    auto se = *mp.rbegin();
                    if(fi.second == 1){
                           if(first[se.first-'a'] < l || last[se.first-'a'] >r) check = true;
                    }
                    if(se.second == 1){
                        if(first[fi.first-'a'] < l || last[fi.first-'a'] >r) check = true;
                    }
                }
                if(!check){
                    mp[s[l]]--;
                    if(mp[s[l]] == 0) mp.erase(s[l]);
                    l++;
                }
            }
            ans = max(ans,r-l+1);
        }
        return ans;
        
    }
};

// we can swap two characters
// we will keep first and last occurence of every letter and then when our window size will become greater than 1 and we will check if it is valid, if it is not valid we will move the right pointer