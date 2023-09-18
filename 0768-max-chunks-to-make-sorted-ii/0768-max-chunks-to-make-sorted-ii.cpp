class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 1;
        int maxi = 0;
        int n = arr.size();
        vector <int> suffix(n);
        suffix[n-1] = arr[n-1];
        for(int i= n-2; i>=0; i--) suffix[i] = min(suffix[i+1],arr[i]);
        for(int i = 0; i <n-1; i++){
            maxi = max(maxi,arr[i]);
            if(maxi <= suffix[i+1]){
                count++;
            }
        }
        return count;
    }
};

/*
we are given an integer array arr
we split arr into some number of chunks and individually sort each chunk
after concatenating them we need a sorted array

2 1 3 4 4
prefix maximum and suffix minimum , if it is getting satisfied at any point we can just create a chunk

2 1 3 4 4
2 2 3 4 4
1 1 3 4 4 


*/