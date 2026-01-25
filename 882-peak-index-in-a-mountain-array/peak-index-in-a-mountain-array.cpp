class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st=1,end=arr.size()-2,maxi=0,k;
    
        while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])// 1 7 4 1 3
        return mid;
        else if(arr[mid]<arr[mid+1])//
        st=mid+1;
        else
        end=mid-1;
        }
      return -1;
   
    }
};