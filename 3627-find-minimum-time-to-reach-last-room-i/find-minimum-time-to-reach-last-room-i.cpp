class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size(),m=moveTime[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(top.first>dist[top.second.first][top.second.second]){
                continue;
            }
            for(int i=0;i<4;i++){
                int newx=top.second.first+dx[i];
                int newy=top.second.second+dy[i];
                if(newx>=0 && newx<n && newy>=0 && newy<m){
                    int newTime=0;
                    if(top.first>=moveTime[newx][newy]){
                        newTime=top.first+1;
                    }
                    else{
                        newTime=max(top.first, moveTime[newx][newy]) + 1;;
                    }
                    if(newTime < dist[newx][newy]) {
                        dist[newx][newy] = newTime;
                        pq.push({newTime, {newx, newy}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};