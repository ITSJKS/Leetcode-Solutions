class Solution {
public:
    int find_max(int num){
        string a = to_string(num);
        char ch = '9';
        for(auto x:a){
            if(x!='9'){
                ch = x;
                break;
            }
        }
        for(auto &x:a){
            if(x == ch) x = '9';
        }
        return stoi(a);
    }
    int find_min(int num){
        string a = to_string(num);
        if(a[0] == '1'){
            char ch = '0';
            for(int i = 1; i <a.size(); i++){
                if(a[i]!='0' && a[i]!=a[0]){
                    ch = a[i];
                    break;
                }
            }
            for(int i = 1; i <a.size(); i++){
                if(a[i] == ch){
                    a[i] = '0';
                }
            }
        }
        else{
            char ch = a[0];
            for(auto &x:a){
                if(x == ch){
                    x = '1';
                }
            }
        }
        // cout<<a<<" ";
        return stoi(a);
    }
    int maxDiff(int num) {
        int maxi = find_max(num);
        int mini = find_min(num);
        return maxi - mini ;
    }
};