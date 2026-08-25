class Solution {
public:
    int left(vector<vector<int>>& matrix,int r,int c,vector<vector<int>>& L){
        if(c<0 || matrix[r][c]==0) return 0;
        if(L[r][c]!=-1){
            return L[r][c];
        }
        return L[r][c]=1+left(matrix,r,c-1,L);
    }
    int right(vector<vector<int>>& matrix,int r,int c,vector<vector<int>>& R){
        if(c>=matrix.size() || matrix[r][c]==0) return 0;
        if(R[r][c]!=-1){
            return R[r][c];
        }
        return R[r][c]=1+right(matrix,r,c+1,R);
    }
    int up(vector<vector<int>>& matrix,int r,int c,vector<vector<int>>& U){
        if(r<0 || matrix[r][c]==0) return 0;
        if(U[r][c]!=-1){
            return U[r][c];
        }
        return U[r][c]=1+up(matrix,r-1,c,U);
    }
    int down(vector<vector<int>>& matrix,int r,int c,vector<vector<int>>& D){
        if(r>=matrix.size() || matrix[r][c]==0) return 0;
        if(D[r][c]!=-1){
            return D[r][c];
        }
        return D[r][c]=1+down(matrix,r+1,c,D);
    }
    int solve(vector<vector<int>>& matrix,int r,int c,vector<vector<int>>& dp,vector<vector<int>>& L,vector<vector<int>>& R,vector<vector<int>>& U,vector<vector<int>>& D){
        if(r<0 || r>matrix.size() || c<0 || c>matrix[0].size()) return 0;
        if(matrix[r][c]==0){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int left_dir=left(matrix,r,c,L);
        int right_dir=right(matrix,r,c,R);
        int up_dir=up(matrix,r,c,U);
        int down_dir=down(matrix,r,c,D);
        return dp[r][c]=min({left_dir,right_dir,up_dir,down_dir});
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> matrix(n,vector<int>(n,1));
        for(auto mine:mines){
            matrix[mine[0]][mine[1]]=0;
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<vector<int>> L(n, vector<int>(n, -1));
        vector<vector<int>> R(n, vector<int>(n, -1));
        vector<vector<int>> U(n, vector<int>(n, -1));
        vector<vector<int>> D(n, vector<int>(n, -1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int temp=solve(matrix,i,j,dp,L,R,U,D);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};