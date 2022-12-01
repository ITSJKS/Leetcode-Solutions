class Solution {
public:
    bool halvesAreAlike(string s) {
        string a = s.substr(0,s.length()/2);
        string b = s.substr(s.length()/2);
        string vowels = "aeiouAEIOU";
        int count1 = 0;
        int count2 = 0;
        for(auto x:a){
            if(vowels.find(x)!=string::npos){
                count1++;
            }
        }
        for(auto x:b){
            if(vowels.find(x)!=string::npos){
                count2++;
            }
        }
        return count1 == count2;
    }
};