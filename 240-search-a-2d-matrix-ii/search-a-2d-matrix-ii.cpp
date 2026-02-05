class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st=0;
        int m=matrix[0].size();
        int n=matrix.size();
        int end=m-1;
     

        // int q=m
        while(st<n && end>=0){
            if(matrix[st][end]==target)
            return true;
            else if(matrix[st][end]<target)
            st++;
            else
            end--;
        }
        return false;
    }
};