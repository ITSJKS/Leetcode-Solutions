class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        for(int i = 0; i <n; i++){
            int x = s[i]-'0';
            int maxi = i+1;
            for(int j = i+1; j <n; j++){
                int y = s[j]-'0';
                if(y>=s[maxi]-'0'){
                    maxi = j;
                }
            }
            int y = s[maxi]-'0';
            if(y>x){
                swap(s[i],s[maxi]);
                break;
                }
        }
        return stoi(s);
    }
};