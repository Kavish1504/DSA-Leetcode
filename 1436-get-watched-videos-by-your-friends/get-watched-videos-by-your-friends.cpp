class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<pair<int,int>> q;
        q.push({id,0});
        int l=0;
        vector<bool> visited(watchedVideos.size(),false);
        unordered_map<string,int> mp;
        visited[id]=true;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            if(front.second==level){
                for(auto ch:watchedVideos[front.first]){
                    mp[ch]++;
                }
                continue;
            }
            for(auto neigh:friends[front.first]){
                if(!visited[neigh]){
                    q.push({neigh,front.second+1});
                    visited[neigh]=true;
                }
            }
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<>> pq;
        for(auto num:mp){
            pq.push({num.second,num.first});
        }
        vector<string> ans;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};