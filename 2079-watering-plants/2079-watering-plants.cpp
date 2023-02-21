class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int c = capacity;
        int step = 0;
        int n = plants.size();
        for(int i = 0; i <n; i++){
            if(plants[i] <= c){
                c -= plants[i];
                step++;
            }
            else{
                c = capacity;
                step += 2*i;
                step++;
                c -= plants[i];
            }
        }
        return step;
    }
};