class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0;
        int ans = 0;
        for(auto x:nums){
            if(x == 0){
                pos = 0, neg = 0;
            }
            else if(x > 0){
                pos++;
                if(neg) neg++;
                ans = max(ans,pos);
            }
            else{
                swap(pos,neg);
                if(pos) pos++;
                neg++;
                ans = max(ans,pos);
            }
        }
        return ans;
    }
};
/*

Rough:- we need to keep count of positive and negative , if number of negative is even, we have positive else we have negative in our hand and we can use the last neg to make it positive

Intuition:-
Another way of doing it will be alternating between positive and negative , where positve and negative is maximum length of positve and negative array

Explanation:-

*/
