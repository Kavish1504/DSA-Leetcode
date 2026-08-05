class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto edge:invocations){
            adj[edge[0]].push_back(edge[1]);
        }
        queue<int> q;
        q.push(k);
        vector<bool> suspicious(n,false);
        suspicious[k]=true;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            
            for(auto neigh:adj[front]){
                if(!suspicious[neigh]){
                    suspicious[neigh]=true;
                    q.push(neigh);
                }
            }
        }
        vector<vector<int>> trans(n);
        for(auto edge:invocations){
            int u=edge[0],v=edge[1];
            if(!suspicious[u] && suspicious[v]){
                vector<int> ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!suspicious[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};