class Solution {
public:
bool check(vector<vector<int>>&arr,int target,int row){
    int st=0,end=arr[0].size()-1;
    while(st<=end){
        int mid=(st+end)/2;
        if(arr[row][mid]==target)
        return true;
        else if(arr[row][mid]<target)
        st=mid+1;
        else
        end=mid-1;
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int st=0,end=matrix.size()-1;
     int n=matrix[0].size()-1;
     while(st<=end){
        int mid=(st+end)/2;
        if(matrix[mid][0]<=target && matrix[mid][n]>=target){
               return  check(matrix,target,mid);
        }
        else if(matrix[mid][n]<target)
        st=mid+1;
        else
        end=mid-1;
     }
     return false;
    }
};