class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        vector<bool> visited(arr.size(),false);
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            if(visited[front]) continue;
            if(arr[front]==0) return true;
            if(front-arr[front]>=0) q.push(front-arr[front]);
            if(front+arr[front]<arr.size()) q.push(front+arr[front]);
            visited[front]=true;
        }
        return false;
    }
};