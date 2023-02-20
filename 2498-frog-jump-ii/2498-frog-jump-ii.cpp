class Solution {
public:
    int maxJump(vector<int>& stones) {
        if(stones.size() == 2) return stones[1]-stones[0];
        int maxi = 0;
        for(int i = 3; i <stones.size(); i+=2){
            maxi = max(maxi,stones[i]-stones[i-2]);
        }
        for(int i = 2; i <stones.size(); i+=2){
            maxi = max(maxi,stones[i]-stones[i-2]);
        }
        return maxi;
    }
};