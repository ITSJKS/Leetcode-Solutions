class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        // start  =  k , when we get x = k + 1, then we can't get k as our start is showing what the cur_one we need and we needed k but we can't get k so wer return start
        int start = 1;
        for(auto x:coins){
            if(x > start) return start;
            else start += x;
        }
        return start;
        
    }
};