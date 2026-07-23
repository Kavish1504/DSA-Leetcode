class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<intervals.size();i++){
            pq.push({intervals[i][0],intervals[i][1]});
        }
        vector<vector<int>> result;
        bool start_found=false;
        bool end_found=false;
        int start=newInterval[0];
        int end=newInterval[1];
        while(!pq.empty()){
            auto [s,e]=pq.top();
            pq.pop();
            if(!start_found){
                if(e<start){
                    result.push_back({s,e});
                }
                else if(s>end){
                    result.push_back({start,end});
                    start_found=true;
                    end_found=true;
                    result.push_back({s,e});
                }
                else{
                    start_found=true;
                    start=min(start,s);
                    end=max(end,e);
                }
            }
            else if(start_found && !end_found){
                if(s<=end){
                    end=max(end,e);
                }
                else{
                    end_found=true;
                    result.push_back({start,end});
                    result.push_back({s,e});
                }
            }
            else{
                result.push_back({s,e});
            }
        }
        if(start_found && !end_found){
            result.push_back({start,end});
        }
        if(!start_found){
            result.push_back(newInterval);
        }
        sort(result.begin(),result.end());
        return result;
    }
};