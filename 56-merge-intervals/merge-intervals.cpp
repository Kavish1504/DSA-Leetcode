class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<intervals.size();i++){
            pq.push({intervals[i][0],intervals[i][1]});
        }
        int prev_start=-1,prev_end=-1;
        vector<vector<int>> result;
        while(!pq.empty()){
            auto [s,e]=pq.top();
            pq.pop();
            if(prev_start==-1){
                prev_start=s;
                prev_end=e;
            }
            else{
                if(s>=prev_start && s<=prev_end){
                    prev_end=max(prev_end,e);
                }
                else{
                    if(prev_start!=-1 && prev_end!=-1){
                        result.push_back({prev_start,prev_end});
                    }
                    prev_start=s;
                    prev_end=e;

                }
            }
        }
        result.push_back({prev_start,prev_end});
        return result;
    }
};