class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto edge:times){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});
        dist[k]=0;
        vector<bool> visited(n+1,false);
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(visited[top.second]) continue;
            visited[top.second]=true;
            for(auto neigh:adj[top.second]){
                if((top.first+neigh.second)<dist[neigh.first]){
                    dist[neigh.first]=top.first+neigh.second;
                    pq.push({dist[neigh.first],neigh.first});
                }
            }
        }
        int mini=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            mini=max(mini,dist[i]);
        }
        return mini;
    }
};