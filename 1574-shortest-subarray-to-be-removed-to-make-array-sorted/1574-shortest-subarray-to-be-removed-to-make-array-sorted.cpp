class Solution {
public:
    bool isPossible(vector<int>& arr, int k, vector<bool>& v1, vector<bool>& v2){
        int n=arr.size();
        if(v2[k]==true){
            return true;
        }
        
        if(v1[n-1-k]==true){
            return true;
        }
        
        int l=1;
        int r=k;

        while(r<(n-1)){
            if(v1[l-1]==true and v2[r+1]==true and arr[l-1]<=arr[r+1]){
                    return true;  
            }      
            l++;
            r++;
        }
        return false;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = -1, r = n;
        vector<bool> v1(n,false);
        vector<bool> v2(n,false);
        int s=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>=s){
                v1[i]=true;
                s=arr[i];
            }else{
                break;
            }
        }
        
        s=INT_MAX;
        
        for(int i=n-1;i>=0;i--){
            if(arr[i]<=s){
                v2[i]=true;
                s=arr[i];
            }else{
                break;
            }
        }
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(isPossible(arr,mid,v1,v2)) r = mid;
            else l = mid;
        }
        return r;
    }
};