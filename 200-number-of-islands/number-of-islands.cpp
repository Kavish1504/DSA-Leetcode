class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    void bfs(int x,int y,vector<vector<char>>& grid,vector<vector<bool>>& visited){
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({x,y});
        visited[x][y]=true;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            grid[front.first][front.second]='X';
            for(int i=0;i<4;i++){
                int newx=front.first+dx[i];
                int newy=front.second+dy[i];
                if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]=='1' && !visited[newx][newy]){
                    q.push({newx,newy});
                    visited[newx][newy]=true;
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    bfs(i,j,grid,visited);
                    island++;
                }
            }
        }
        return island;
    }
};