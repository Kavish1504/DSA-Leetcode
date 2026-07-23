class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int start_row=0,start_col=0,end_row=n-1,end_col=n-1;
        int num=1;
        while(start_row <= end_row && start_col <= end_col){
            for(int i=start_col;i<=end_col;i++){
                matrix[start_row][i]=num;
                num++;
            }
            start_row++;

            for(int i=start_row;i<=end_row;i++){
                matrix[i][end_col]=num;
                num++;
            }
            end_col--;

            for(int i=end_col;i>=start_col;i--){
                matrix[end_row][i]=num;
                num++;
            }

            end_row--;

            for(int i=end_row;i>=start_row;i--){
                matrix[i][start_col]=num;
                num++;
            }
            start_col++;
        }
        return matrix;
    }
};