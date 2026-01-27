class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if(m==0){
        // nums1=nums2;
        // return;
        // }
        //      if(n==0){
    
        // }
      
        int i=m-1,j=n-1;
        int ind=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]<nums2[j]){
                nums1[ind--]=nums2[j--];
              
            }
                else{
                nums1[ind--]=nums1[i--];
            
            }
        }
        while(j>=0){
            nums1[ind]=nums2[ind];
            ind--;j--;
        }
       // return nums1;
    }
};