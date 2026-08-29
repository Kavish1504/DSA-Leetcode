class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,vector<pair<char,int>>> adj;
        for(int i=0;i<original.size();i++){
            adj[original[i]].push_back({changed[i],cost[i]});
        }
        long long total_cost=0;
        vector<vector<long long>> dist(26,vector<long long>(26,LLONG_MAX));
        for(int start=0;start<26;start++){
            priority_queue<pair<int,char>,vector<pair<int,char>>,greater<>> pq;
            pq.push({0,'a'+start});
            dist[start][start]=0;
            while(!pq.empty()){
                auto front=pq.top();
                pq.pop();
                if(front.first>dist[start][front.second-'a']){
                    continue;
                }
                for(auto num:adj[front.second]){
                    int neigh=num.first-'a';
                    if(num.second+front.first<dist[start][neigh]){
                        dist[start][neigh] =num.second+front.first;

                        pq.push({
                            dist[start][neigh],
                            num.first
                        });
                    }
                }
            }
        }
        for(int i = 0; i < source.size(); i++) {

            if(source[i] == target[i])
                continue;

            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(dist[u][v] == LLONG_MAX)
                return -1;

            total_cost += dist[u][v];
        }

        return total_cost;
    }
};