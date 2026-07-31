class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(n>1 && m>1 && grid[0][1]>1 && grid[1][0]>1) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> q;
        int time=0;
        q.push({0,{0,0}});
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        while(!q.empty()){
            auto front=q.top();
            q.pop();
            time=front.first;
            if(front.second.first==n-1 && front.second.second==m-1) return time;
            if(front.first>dist[front.second.first][front.second.second]) continue;
            for(int i=0;i<4;i++){
                int newx=front.second.first+dx[i];
                int newy=front.second.second+dy[i];
                if(newx<0 || newx>=n || newy<0 || newy>=m){
                    continue;
                }
                int arrive=max(time+1,grid[newx][newy]);
                if((arrive-(time+1))%2==1)
                    arrive++;
                if(arrive<dist[newx][newy]){
                    dist[newx][newy]=arrive;
                    q.push({arrive,{newx,newy}});
                }
            }
        }
        return -1;
    }
};