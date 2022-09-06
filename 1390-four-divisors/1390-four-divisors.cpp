class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums){
            int y = find_divisor(x);
            if(y!=-1) sum += y;
        }
        return sum;
    }
    int find_divisor(int n){
        vector <int> ans;
        for(int i = 1; i*i <= n; i++){
            if(n%i == 0){
                ans.push_back(i);
                if(i*i!=n) ans.push_back(n/i);
            }
            if(ans.size()>4) return -1;
            
        }
        // return ans;
        if(ans.size() == 4){
            return accumulate(ans.begin(),ans.end(),0);
        }
        else{
            return -1;
        }
    }
};