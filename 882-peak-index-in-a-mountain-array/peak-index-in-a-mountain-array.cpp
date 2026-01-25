class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st=0,end=arr.size()-1,maxi=0,k;
      for(int i=1;i<arr.size();i++){
        if(arr[i-1]<arr[i])
        {
            maxi=max(maxi,arr[i]);
            k= i;
        }
      }
      return k;
   
    }
};