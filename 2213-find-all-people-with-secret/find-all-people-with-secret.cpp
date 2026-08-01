class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<pair<int,int>>> mp;
        for(auto m:meetings){
            mp[m[2]].push_back({m[0],m[1]});
        }
        vector<bool> knows(n,false);
        knows[0]=true;
        knows[firstPerson]=true;
        for(auto [time,edges]:mp){
            unordered_map<int,vector<int>> adj;
            unordered_set<int> people;
            for(auto edge:edges){
                adj[edge.first].push_back(edge.second);
                adj[edge.second].push_back(edge.first);
                people.insert(edge.first);
                people.insert(edge.second);
            }
            queue<int> q;
            unordered_set<int> vis;
            for(int p:people){
                if(knows[p]){
                    q.push(p);
                    vis.insert(p);
                }
            }
            
            while(!q.empty()){
                auto front=q.front();
                q.pop();
                knows[front]=true;
                for(auto neigh:adj[front]){
                    if(!vis.count(neigh)){
                        vis.insert(neigh);
                        q.push(neigh);
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(knows[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};