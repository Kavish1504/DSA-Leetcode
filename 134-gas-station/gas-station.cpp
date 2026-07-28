class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0,currgas=0,start=0;
        for(int i=0;i<gas.size();i++){
            int diff=gas[i]-cost[i];
            totalgas+=diff;
            currgas+=diff;
            if(currgas<0){
                start=i+1;
                currgas=0;
            }
        }
        return totalgas>=0?start:-1;
    }
};