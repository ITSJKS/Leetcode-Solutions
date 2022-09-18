class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();
        int low = 0, high = n -1;
        int leftmax = 0, rightmax = 0;
        int water = 0;
        while(low<high){
            if(height[low]<=height[high]){
                if(leftmax > height[low]){ water += (leftmax - height[low]);
                                         }
                else{
                    leftmax = height[low]; 
                }
                low++;
                
            }
            else{
                if(rightmax >height[high]){
                    water+= (rightmax-height[high]);
                }
                else{
                    rightmax = height[high];
                }
                high --;
            }
        }
        return water;
        
    }
};