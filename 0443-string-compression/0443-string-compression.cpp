class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 1;
        int j = 1;
        int count = 1;
        int n = chars.size();
        for(int j = 1; j <n; j++){
            if(chars[j] == chars[j-1]){
                count++;
            }
            else{
                if(count>1){
                    string x = to_string(count);
                    for(auto y:x){
                        chars[i] = y;
                        i++;
                    }
                    
                }
                chars[i] = chars[j];
                i++;
                count = 1;
            }
        }
        if(count>1){
                    string x = to_string(count);
                    for(auto y:x){
                        chars[i]  = y;
                        i++;
                    }
                    
                }
    
        return i;
    }
};