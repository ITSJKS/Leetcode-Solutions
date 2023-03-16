class Solution {
public:
    // increasing then nums[i]<nums[i+1] we will try to put the smallest avaiable until now 
    // decreasing then nums[i]>nums[i+1] we will try to put the 2nd smallest available until now at i and smallest at i + 1
    string smallestNumber(string p) {
        int n = p.size();
        string v;
        for(int i = 1; i <=n+1; i++){
            v.push_back(i+'0');
        }
        do{
            bool check = true;
            for(int i = 0; i <n; i++){
                if(p[i] == 'I'){
                    check = check &&(v[i+1]>v[i]);
                }
                else{
                    check = check && (v[i+1]<v[i]);
                }
            }
            if(check){
                return v;
            }
        }
        while(next_permutation(v.begin(),v.end()));
        return "";
    }
};