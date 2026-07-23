class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> mp;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    mp.push_back({i,j});
                }
            }
        }
        for(auto [r,c]:mp){
            for(int i=0;i<n;i++){
                matrix[i][c]=0;
            }
            for(int i=0;i<m;i++){
                matrix[r][i]=0;
            }
        }
    }
};