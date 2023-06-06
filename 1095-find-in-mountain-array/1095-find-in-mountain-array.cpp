/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bs(int target, MountainArray &arr, int l , int r,int type){
        while(l <= r){
            int mid = l + (r-l)/2;
            int num = arr.get(mid);
            if(num == target) return mid;
            else if(num < target){
                if(type) l = mid+1;
                else r = mid-1;
            } 
            else{
                if(type) r = mid-1;
                else l = mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int l = 0, r = n-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(arr.get(mid) < arr.get(mid+1)) l = mid+1;
            else r = mid;
        }
        int idx = l;
        if(arr.get(idx) == target) return idx;
        // check in sorted order from 0 to idx-1
        idx = bs(target,arr,0,idx-1,1);
        if(idx!=-1) return idx;
        idx = bs(target,arr,idx+1,n-1,0);
        if(idx!=-1) return idx;
        return -1;
        // check in reverse sorted order from idx+1, to n-1
    }
};