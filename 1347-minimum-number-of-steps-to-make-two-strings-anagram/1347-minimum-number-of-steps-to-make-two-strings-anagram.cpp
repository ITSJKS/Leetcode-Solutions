class Solution {
public:
    int minSteps(string s, string t) {
        vector <int> freq1(26),freq2(26,0);
        for(auto x:t) freq2[x-'a']++;
        for(auto x:s) freq1[x-'a']++;
        int count = 0;
        for(int i = 0; i <26; i++){
            if(freq2[i] == freq1[i]) continue;
            else{
                count += abs(freq2[i]-freq1[i]);
            }
        }
        return count/2;
    }
};