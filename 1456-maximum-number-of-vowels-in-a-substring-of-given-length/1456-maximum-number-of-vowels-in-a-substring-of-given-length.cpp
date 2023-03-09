class Solution {
public:
    int maxVowels(string s, int k) {
        int v = 0;
        int maxi = 0;
        set <char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');

        int n = s.size();
        for(int i = 0; i <n; i++){
            if(i <k){
                if(vowels.count(s[i])){
                    v++;
                }
                if(i == k - 1) maxi = v;
            }
            else{
                if(vowels.count(s[i-k])) v--;
                if(vowels.count(s[i])) v++;
                maxi = max(maxi,v);
            }
        }
        return maxi;
    }
};