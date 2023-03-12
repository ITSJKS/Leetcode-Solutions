class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int start = 0, end = n - 1;
        int coins = 0;
        while(end - start >=2){
            coins+=piles[end-1];
            end-=2;
            start++;
        }
        return coins;
    }
};
// 1 2 and 6th
// 3 4 and 5th