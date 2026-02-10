class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool flag1=true;
        bool flag2=true;

        for(auto p:nums1)
        if(p!=0){
        flag1=false;
    break;}
        for(auto p:nums2)
        if(p!=0){
        flag2=false;
    break;}
    if(flag1==true && flag2==true)
    return 0;
        double med;
        int m=nums1.size();
        int n=nums2.size();
        vector<int>nums3;
    for(int i=0;i<m;i++)
        nums3.push_back(nums1[i]);
        for(int i=0;i<n;i++)
        nums3.push_back(nums2[i]);

        sort(nums3.begin(),nums3.end());
        int l=nums3.size();
    if(l%2!=0)
    med=nums3[l/2];
    else
    {
        med=(nums3[l/2-1]+nums3[l/2])/2.0;
        
    }

        return med;    

    }
};