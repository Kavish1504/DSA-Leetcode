class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.rbegin(),processorTime.rend());
        sort(tasks.begin(),tasks.end());
        long long min_time=LLONG_MIN;
        for(int i=0;i<processorTime.size();i++){
            for(int j=0;j<4;j++){
                min_time=max(min_time,(long long)processorTime[i]+tasks[4*i+j]);
            }
        }
        return min_time;
    }
};