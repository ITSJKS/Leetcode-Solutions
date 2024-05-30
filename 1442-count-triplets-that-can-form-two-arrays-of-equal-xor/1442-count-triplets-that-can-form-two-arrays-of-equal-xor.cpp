class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size()+1;
        vector <int> prefix(n,0);
        for(int i = 0; i <n-1; i++){
            prefix[i+1] = arr[i]^prefix[i]; 
        }
        int ans = 0;
        for(int i = 0; i <n; i++){
            for(int j = i+1; j <n; j++){
                if(prefix[i] == prefix[j]){
                    ans += j - i -1;
                }
            }
        }
        return ans;
        
    }
};