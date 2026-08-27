class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row=mat.size(),col=mat[0].size();
        if((row*col)!=(r*c)) return mat;
        vector<vector<int>> ans(r,vector<int>(c,0));
        int new_row=0,new_col=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans[new_row][new_col]=mat[i][j];
                new_col++;
                if(new_col>=c){
                    new_col=0;
                    new_row++;
                }
            }
        }
        return ans;
    }
};