class Solution {
public:
    bool isSafe(vector<string>& ans,int row,int col){
        for(int i=0;i<row;i++){
            if(ans[i][col]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(ans[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0 && j<ans.size();i--,j++){
            if(ans[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void queenplace(vector<vector<string>>& ans,vector<string>& result,int row,int n){
        if(row==n){
            ans.push_back(result);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(result,row,col)){
                result[row][col]='Q';
                queenplace(ans,result,row+1,n);
                result[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> result(n,string(n,'.'));
        queenplace(ans,result,0,n);
        return ans;
    }
};