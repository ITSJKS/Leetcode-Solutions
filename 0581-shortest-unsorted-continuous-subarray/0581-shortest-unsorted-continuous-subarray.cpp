class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*
        another way would be to sort the array and then check on it 
        2 6 4 8 10 9 15
        after sorting 
        2 4 6 8 9 10 15
        we can just find the point where it is satisying in left and right part and then just return the answer
        */
        int n = nums.size();
        vector <int> v = nums;
        sort(nums.begin(),nums.end());
        int i = 0, j = n-1;
        while(i < n && nums[i] == v[i]) i++;
        while(j >=0 && nums[j] == v[j]) j--;
        if(i > j) return 0;
        return j-i+1;
    }
};

// continous subarray such that if we sort this subarray whole array will be sorted
// we can just find the prefix maximum upto which our array was sorted 
// we can find prefix minimum as well as point upto which our array was sorted
// then we can traverse in the prefix and check if minimum in the middle portion is greater than current element and maximum is less than right part