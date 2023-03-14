class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int color = 0;
        int ans = n;
        for(int i = 0; i <n; i++){
            color += (blocks[i] == 'B');
            if(i >=k-1){
                ans = min(ans,k - color);
                if(blocks[i-k+1] == 'B') color--;
            } 
        }
        return ans;
    }
};