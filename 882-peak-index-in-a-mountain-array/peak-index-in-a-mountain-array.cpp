class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st=0,end=arr.size()-1,maxi=0,k;
    
        while(st<end){
        int mid=st+(end-st)/2;
        if(arr[mid]<arr[mid+1])//1 7 6 5 4
        st=mid+1;
        else
        end=mid;
        }
      return st;
   
    }
};