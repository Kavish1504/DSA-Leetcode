class Solution {
public:
    bool findunsigned(vector<vector<char>>& mat,int& row,int& col){
        for(row=0;row<mat.size();row++){
            for(col=0;col<mat[0].size();col++){
                if(mat[row][col]=='.'){
                    return true;
                }
            }
        }
        return false;
    }
    bool rowverify(vector<vector<char>>& mat,int row,int col,int num){
        for(int i=0;i<9;i++){
            if(mat[row][i]==num+'0'){
                return true;
            }
        }
        return false;
    }
    bool colverify(vector<vector<char>>& mat,int row,int col,int num){
        for(int i=0;i<9;i++){
            if(mat[i][col]==num+'0'){
                return true;
            }
        }
        return false;
    }
    bool boxassign(vector<vector<char>>& mat,int row,int col,int num){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(mat[i+row][j+col]==num+'0'){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to find a solved Sudoku.
    bool verify(vector<vector<char>>& mat,int row,int col,int num){
        return !rowverify(mat,row,col,num) && !colverify(mat,row,col,num) && !boxassign(mat,row-row%3,col-col%3,num);
    }
    bool solve(vector<vector<char>>& mat){
        int row,col;
        if(!findunsigned(mat,row,col)){
            return true;
        }
        for(int num=1;num<=9;num++){
            if(verify(mat,row,col,num)){
                mat[row][col]=num+'0';
                if(solve(mat)){
                    return true;
                }
                mat[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};