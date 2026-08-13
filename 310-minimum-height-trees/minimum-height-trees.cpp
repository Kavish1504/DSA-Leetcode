class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        vector<int> res;
        unordered_map<int,int> heights;
        while(n>2){
            int size=q.size();
            n-=size;
            while(size--){
                int front=q.front();
                q.pop();
                for(auto neigh:adj[front]){
                     indegree[neigh]--;
                    if(indegree[neigh]==1){
                        q.push(neigh);
                    }
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};