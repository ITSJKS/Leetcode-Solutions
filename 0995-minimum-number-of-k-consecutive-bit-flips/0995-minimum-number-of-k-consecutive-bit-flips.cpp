class Solution {
public:
    int minKBitFlips(vector<int>& v, int k) {
        auto final_bit = [&](bool bit,int flips){
            if(flips&1) return !bit;
            return bit;
        };
        int n = v.size();
        vector <int> prefix(n+1);
        int count = 0;
        for(int i = 0; i <n; i++){
            if(i>0) prefix[i]+= prefix[i-1];
            if(i < n- k + 1){
                int flips = prefix[i];
                int bit = final_bit(v[i],flips);
                if(bit == 1) continue;
                count++;
                prefix[i]++;
                prefix[i+k]--;
            }
        }
        for(int i = 0; i<n; i++){
            if(final_bit(v[i],prefix[i]) == 0) return -1; 
        }
        return count;
    }
};

/*
We need to find minimum number of k-bit flip required so that there is on 0 in the array
when k == 1 , ans is number of 0
when k == 2, we can convert it by pushing all 0 into the end and converting them into one by one move
or we can push them into start , which ever will be easier
1 0 1 0 1 0 1 0 1 1


*/
