class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows=heightMap.size(),cols=heightMap[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        for(int i=0;i<rows;i++){
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][cols-1],i,cols-1});
            visited[i][0]=visited[i][cols-1]=true;
        }
        for(int j=0;j<cols;j++){
            pq.push({heightMap[0][j],0,j});
            pq.push({heightMap[rows-1][j],rows-1,j});
            visited[0][j]=visited[rows-1][j]=true;
        }
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,-1,1};
        int ans=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            for(int k=0;k<4;k++){
                int newx=top[1]+dx[k];
                int newy=top[2]+dy[k];
                if(newx>=0 && newx<rows && newy>=0 && newy<cols && !visited[newx][newy]){
                    ans+=max(0,top[0]-heightMap[newx][newy]);
                    pq.push({max(heightMap[newx][newy],top[0]),newx,newy});
                    visited[newx][newy]=true;
                }
            }
        }
        return ans;
    }
};