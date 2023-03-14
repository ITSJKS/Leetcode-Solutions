class Solution {
public:
    string largestPalindromic(string num) {
        vector <int> freq(10,0);
        for(auto x:num){
            freq[x-'0']++;
        }
        string part1;
        for(int i = 9; i>=0; i--){
            if(freq[i]){
                if(i == 0 && part1.size() == 0) continue;
                int size = freq[i];
                for(int j = 0; j<size/2; j++){
                    part1.push_back(i+'0');
                }
                freq[i]-=(size/2)*2;
            }
        }
        string part2 = part1;
        for(int i = 9; i>=0; i--){
            if(freq[i]){
                part1.push_back(i+'0');
                break;
            }
        }
        reverse(part2.begin(),part2.end());
        return part1 + part2;
    }
};