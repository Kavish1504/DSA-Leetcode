class Solution {
public:
    void dfs(vector<int>& values,vector<vector<pair<int,int>>>& adj,vector<int>& visited,int& val,int node,int score,int time,int maxTime){
        if(time>maxTime) return;
        if(visited[node]==0) score+=values[node];
        visited[node]++;
        if(node==0){
            val=max(val,score);
        }
        for(auto neigh:adj[node]){
            int newtime=neigh.second+time;
            int newnode=neigh.first;
            dfs(values,adj,visited,val,newnode,score,newtime,maxTime);
        }
        visited[node]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        int val=values[0];
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<int> visited(n,false);
        dfs(values,adj,visited,val,0,0,0,maxTime);
        return val;
    }
};