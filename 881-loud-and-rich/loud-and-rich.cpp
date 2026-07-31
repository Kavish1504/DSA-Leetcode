class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> adj(quiet.size());
        for(auto rich:richer){
            adj[rich[1]].push_back(rich[0]);
        }
        vector<int> ans(quiet.size());
        for(int i=0;i<quiet.size();i++){
            int min_quietness=quiet[i];
            int curr_node=i;
            queue<pair<int,int>> q;
            q.push({i,quiet[i]});
            vector<bool> visited(quiet.size(),false);
            visited[curr_node]=true;
            while(!q.empty()){
                auto front=q.front();
                q.pop();
                if(front.second<min_quietness){
                    min_quietness=front.second;
                    curr_node=front.first;
                }
                for(auto neigh:adj[front.first]){
                    if(!visited[neigh]){
                        visited[neigh]=true;
                        q.push({neigh,quiet[neigh]});
                    }
                }
            }
            ans[i]=curr_node;
        }
        return ans;
    }
};