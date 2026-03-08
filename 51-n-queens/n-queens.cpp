class Solution {
public:
    bool isSafe(vector<string>&bored,int col,int n,int row){
        //row wise
        for(int i=0;i<n;i++){
            if(bored[row][i]=='Q')
            return false;
        }
        //col wise
        for(int i=0;i<n;i++){
            if(bored[i][col]=='Q')
            return false;
        }
        //digonal right
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
              if(bored[i][j]=='Q')
            return false;
        }
           //digonal left
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
              if(bored[i][j]=='Q')
            return false;
        }
        return true;
    }

    void calc(vector<vector<string>>&ans,vector<string> &bored,int n,int indx){
        if(indx==n)
        {
            ans.push_back(bored);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isSafe(bored,i,n,indx)){
                bored[indx][i]='Q';
                calc(ans,bored,n,indx+1);
            
                bored[indx][i]='.';
                }
            
        }
    }

    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
        vector<string>bored(n,string(n,'.'));
        calc(ans,bored,n,0);
        return ans;

    }
};