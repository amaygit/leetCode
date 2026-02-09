class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     int top=0,bottom=matrix.size()-1;
     int left=0,right=matrix[0].size()-1;
    vector<int>p;
     while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++)
        p.push_back(matrix[left][i]);
        top++;
        for(int i=top;i<=bottom;i++)
        p.push_back(matrix[i][right]);
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--)
            p.push_back(matrix[bottom][i]);
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--)
            p.push_back(matrix[i][left]);
            left++;
        }
     }
     return p;
    }
};