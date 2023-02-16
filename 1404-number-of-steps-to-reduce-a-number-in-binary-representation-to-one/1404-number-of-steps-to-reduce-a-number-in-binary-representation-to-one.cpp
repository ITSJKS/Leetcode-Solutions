class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        int n = s.size();
        bool check = false;
        for(int i = n-1; i >0; i--){
            if(s[i] == '1' && !check) check = true,count++;
            if(check){
                if(s[i] == '0') count += 2;
                else count++;
            }
            else count += 1;   
        }
        return count + check;
    }
};