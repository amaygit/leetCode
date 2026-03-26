class Solution {
    bool isSafe(int row,int col,vector<string>&board,int n){
        //row check
        for(int i=0;i<n;i++){
            if(board[row][i]=='Q')
            return false;
        }
//Col check
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q')
            return false;
        }//left diagonal check
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q')
            return false;
        }//right diagonal check
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q')
            return false;
        } return true;
    }
    void solve(int indx,int n, vector<string>&board, vector<vector<string>>&ans){
        if(indx==n ){
            ans.push_back(board);return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(indx,i,board,n)){
                board[indx][i]='Q';
                solve(indx+1,n,board,ans);
                board[indx][i]='.';

            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
   
        vector<vector<string>>ans;
        solve(0,n,board,ans);
        return ans;
    }
};