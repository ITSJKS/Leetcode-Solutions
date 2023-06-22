class Solution {
public:
    int largestVariance(string s) {
        vector <int> freq(26,0);
        for(auto &x:s){
            freq[x-'a']++;
        }
        int global = 0;
        for(int i = 0; i <26; i++){
            for(int j = 0; j <26; j++){
                if(i == j || freq[i] == 0 || freq[j] == 0) continue;
                char minor = j + 'a';
                char major = i + 'a';
                int rest = freq[j];
                int majorcount = 0;
                int minorcount = 0;
                for(auto &x:s){
                    if(x == major) majorcount++;
                    if(x == minor) minorcount++,rest--;
                    if(minorcount > 0) global = max(global,majorcount - minorcount);
                    if(majorcount < minorcount && rest > 0){
                        majorcount =  0;
                        minorcount = 0;
                    }
                }
            }
        }
        return global;
    }
};
// Figured out we need to work on any two char out of 26 at at time , thought of something like a prefix of those two character couldn't find any way also tag was dp so had to see the kadane intuition
// The TC will be O(26*26*n) which would be okay for this problem
// Need to think more of how to use kadane , 