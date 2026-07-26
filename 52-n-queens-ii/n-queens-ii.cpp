class Solution {
public:
    bool canplace(int n,vector<vector<int>>& grid,int x,int y){
        for(int i=x;i>=0;i--){
            if(grid[i][y]==1) return false;
        }
        for(int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--){
            if(grid[i][j] == 1)
                return false;
        }

        for(int i = x-1, j = y+1; i >= 0 && j < n; i--, j++){
            if(grid[i][j] == 1)
                return false;
        }
        return true;
    }
    int solve(int n,vector<vector<int>>& grid,int row){
        if(row==n) return 1;
        int ways=0;
        for(int j=0;j<n;j++){
            if(canplace(n,grid,row,j)){
                grid[row][j]=1;
                ways+=solve(n,grid,row+1);
                grid[row][j]=0;
            }
        }
        
        return ways;
    }
    int totalNQueens(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        return solve(n,grid,0);
    }
};