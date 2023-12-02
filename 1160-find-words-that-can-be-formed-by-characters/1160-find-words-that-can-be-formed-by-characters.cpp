class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector <int> freq(26,0);
        for(auto &x:chars) freq[x-'a']++;
        int count = 0;
        for(auto &x:words){
            vector <int> cur(26,0);
            for(auto &y:x){
                cur[y-'a']++;
            }
            bool check = true;
            for(int i = 0; i <26; i++){
                if(cur[i]>freq[i]) check = false;
        }
            count += check?x.size():0;
        }
        return count;
    }
};