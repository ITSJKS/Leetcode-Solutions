class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector <int> freq2(26,0);
        for(auto x:words2){
            vector <int> freq1(26,0);
            for(auto y:x){
                freq1[y-'a']++;
            }
            for(int i = 0; i <26; i++){
                freq2[i] = max(freq1[i],freq2[i]);
            }
        }
        vector <string> ans;
        for(auto x:words1){
            vector <int> temp = freq2;
            for(auto y:x){
                if(temp[y-'a']>0) temp[y-'a']--;
            }
            bool check = true;
            for(auto y:temp){
                if(y!=0) check = false;
            }
            if(check) ans.push_back(x);
        }
        return ans;
    }
};