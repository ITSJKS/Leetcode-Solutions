class Solution {
public:
    int minimumRefill(vector<int>& plants, int ca, int cb) {
        int cA = ca;
        int cB = cb;
        int n = plants.size();
        int i = 0, j = n-1;
        int count = 0;
        while(i <= j){
            if(i == j){
                if(cb > ca){
                    if(cb >= plants[j])
                        cb -= plants[j];
                    else{
                        count++;
                        cb = cB - plants[j];
                    }
                }
                else{
                    if(ca >= plants[i]){
                        ca -= plants[i];
                    }
                    else{
                        count++;
                        ca = cA - plants[i];
                    }
                }
                i++;
                j--;
            }
            else{
                if(plants[i]<=ca){
                    ca -= plants[i];
                }
                else{
                    count++;
                    ca = cA - plants[i];
                }
                if(plants[j]<=cb){
                    cb -= plants[j];
                }
                else{
                    cb = cB-plants[j];
                    count++;
                }
                i++;
                j--;
            }
        }
        return count;
    }
};