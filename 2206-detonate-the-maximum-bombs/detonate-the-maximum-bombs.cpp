class Solution {
public:
    void dfs(vector<vector<int>>& adj,int node,vector<bool>& visited,int& c){
        visited[node]=true;
        c++;
        for(auto neigh:adj[node]){
            if(!visited[neigh]){
                dfs(adj,neigh,visited,c);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            long long x=bombs[i][0];
            long long y=bombs[i][1];
            long long r=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i!=j){
                    long long x1,y1;
                    x1=abs(x-bombs[j][0]);
                    y1=abs(y-bombs[j][1]);
                    if(x1*x1+y1*y1<=r*r){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int c=0;
            vector<bool> visited(n,false);
            dfs(adj,i,visited,c);
            ans=max(ans,c);
        }
        return ans;
    }
};