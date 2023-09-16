class Solution {
public:
    double merge(vector <int>&num1, vector <int>&num2){
        int i = 0,j = 0;
        int n  = num1.size();
        int m = num2.size();
        int total = n + m;
        int mid;
        if(total&1) mid = (total+1)/2;
        else mid = (total/2) + 1;
        int cur = 0;
        int prev = 0;
        while(i < n && j < m){
            int res;
            if(num1[i] <= num2[j]){
                res = num1[i];
                i++;
            }
            else{
                res = num2[j];
                j++;
            }
            cur++;
            if(cur == mid){
                if(total&1) return res;
                else return (res + prev)/(2.0);
            }
            prev = res;
        }
        while(i < n){
            int res = num1[i];
            i++;
            cur++;
            if(cur == mid){
                if(total&1) return res;
                else return (res + prev)/(2.0);
            }
            prev = res;
        }
        while(j < m){
            int res = num2[j];
            j++;
            cur++;
            if(cur == mid){
                if(total&1) return res;
                else return (res + prev)/(2.0);
            }
            prev = res;
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return merge(nums1,nums2);
    }
};

// there are few we can do this
// first approach
/*
we can just push second vector into first and then just sort it using merge sort or inbuilt function
 2nd approach
 As array is already sorted we can just merge them using some merging algorithm like a two pointer and then we can just find the middle element of that merged vector by diving size/2 by checking odd and even
 
 3rd approach
 as we are given that array is already sorted and we know the size of the 
*/