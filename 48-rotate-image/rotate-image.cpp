class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // int col1=0,col2=m-1;
        // while(col1<col2){
        //     for(int i=0;i<n;i++){
        //         swap(matrix[i][col1],matrix[i][col2]);
        //     }
        //     col1++;
        //     col2--;
        // }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};