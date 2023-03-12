class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int coins = 0;
        int  n = piles.size();
        for(int i = n/3; i < n; i+=2){
            coins += piles[i];
        }
        return coins;
    }
};
// 1 2 and 6th
// 3 4 and 5th