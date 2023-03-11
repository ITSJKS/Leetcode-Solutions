class Solution {
public:
    int minSteps(string s, string t) {
        if(s.size() < t.size()) swap(s,t);
        vector <int> freq1(26,0) , freq2(26,0);
        for(auto x:s){
            freq1[x-'a']++;
        }
        for(auto x:t) freq1[x-'a']--;
        int count = 0;
        for(int i = 0; i <26; i++){
            if(freq1[i]!=0) count += abs(freq1[i]);
        }
        return count;
    }
};