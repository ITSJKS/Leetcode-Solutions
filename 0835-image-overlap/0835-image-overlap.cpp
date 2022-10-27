class Solution {
public:
    int calculate(vector<vector<int>>& img1, vector<vector<int>>& img2){
        int n = img1.size();
        int count = 0;
        for(int i = 0; i <n; i++){
            for(int j = 0; j<n; j++){
                if(img1[i][j] == 1 && (img1[i][j] == img2[i][j])) count++;
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector <int> c1,c2;
        int n = img1.size();
        for(int i = 0; i <n*n; i++){
            if(img1[i/n][i%n]){
                c1.push_back(100*(i/n) + i%n);
            }
        }
        for(int i = 0; i <n*n; i++){
            if(img2[i/n][i%n]){
                c2.push_back(100*(i/n) + i%n);
            }
        }
        unordered_map <int,int> count;
        int maxi = 0;
        for(auto x:c1){
            for(auto y:c2){
                count[x-y]++;
            }
        }
        for(auto x:count) maxi = max(maxi,x.second);
        return maxi;
    }
};