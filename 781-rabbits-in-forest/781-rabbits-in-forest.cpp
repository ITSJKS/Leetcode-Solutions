class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map <int,int> count;
        int ans = 0;
        for(auto x:answers){
            if(x == 0) ans++;
            else{
                if(count[x]==0) ans += x + 1;
                count[x]++;
                if(count[x]==x+1)
                    count[x] = 0;
                }
            }
        return ans;
    }
};