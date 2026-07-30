class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,int> node1_dist;
        unordered_map<int,int> node2_dist;
        queue<pair<int,int>> q;
        q.push({node1,0});
        node1_dist[node1]=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int node=front.first;
            int dist=front.second;

            if(edges[node]==-1) continue;

            int next=edges[node];

            if(!node1_dist.count(next)){
                node1_dist[next]=dist+1;
                q.push({next,dist+1});
            }
        }
        q.push({node2,0});
        node2_dist[node2]=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int node=front.first;
            int dist=front.second;

            if(edges[node]==-1) continue;

            int next=edges[node];

            if(!node2_dist.count(next)){
                node2_dist[next]=dist+1;
                q.push({next,dist+1});
            }
            
        }

        int mini=INT_MAX;
        int ans=-1;
        for(auto num:node1_dist){
            if(node2_dist.count(num.first)){
                int curr=max(num.second,node2_dist[num.first]);
                if(curr<mini){
                    mini=curr;
                    ans=num.first;
                }
                else if(curr == mini){
                    ans = min(ans, num.first);
                }
            }
        }
        return ans;
    }
};