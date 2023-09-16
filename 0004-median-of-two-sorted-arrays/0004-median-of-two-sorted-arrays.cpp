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
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2,nums1);
        int left = (n+m+1)/2;
        int low = 0, high = n;
        while(low <= high){
            int mid1 = low + (high-low)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN,l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n) r1 = nums1[mid1];
            if(mid2 < m) r2 = nums2[mid2];
            if(mid1 >= 1) l1 = nums1[mid1-1];
            if(mid2 >= 1) l2  = nums2[mid2-1];
            if(l1 > r2) high = mid1-1;
            else if(l2 > r1) low = mid1 + 1;
            else{
                if((n+m)%2 == 1) return max(l1,l2);
                return (max(l1,l2) + min(r1,r2))/2.0;
            }
        }
        return 0;
    }
};

// there are few we can do this
// first approach
/*
we can just push second vector into first and then just sort it using merge sort or inbuilt function
 2nd approach
 As array is already sorted we can just merge them using some merging algorithm like a two pointer and then we can just find the middle element of that merged vector by diving size/2 by checking odd and even
 
 3rd approach
As we are given that array is already sorted and we know the size of the 
we can think of some binary search approach,

We can do binary search on the first array
for every mid , I will try to find number of element which is less than mid in first array and second array
if that count is greater than or equal to mid/2 it is my answer else I will check on the second array if any mid satisfies the property we will get out answer
 

 
*/