class Solution {
public:
    int min_hour(vector <int> &piles,int k){
        int count =  0;
        for(auto x:piles){
            count += (x+k-1)/k;
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(),piles.end());
        int low = 1;
        int high = maxi;
        while(low<high){
            int mid = low + (high-low)/2;
           int hours =  min_hour(piles,mid);
            if(hours>h){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};