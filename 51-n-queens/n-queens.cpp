class Solution {
public:
bool isSafe(int row,vector<string>&temp,int col,int n){
    //row wise
    for(int i=0;i<row;i++){
        if(temp[i][col]=='Q')
        return false;
    }
      //Col wise
    for(int j=0;j<col;j++){
        if(temp[row][j]=='Q')
        return false;
    }
    //diagonal right side
     
          for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
        if(temp[i][j]=='Q')
        return false;
    }
     //diagonal left side
       for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
        if(temp[i][j]=='Q')
        return false;
    }
    return true;
}
    void calc(int n,vector<vector<string>>&ans,vector<string>&temp,int row){
        if(row==n){
        ans.push_back({temp});
        return ;
        }
        for(int j=0;j<n;j++){
            if(isSafe(row,temp,j,n)){
                temp[row][j]='Q';
            calc(n,ans,temp,row+1);
            temp[row][j]='.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> temp(n, string(n, '.'));
        calc(n,ans,temp,0);
        return ans;
    }
};