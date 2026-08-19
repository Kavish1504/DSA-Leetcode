class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<bool>> visited;
        for(int i=0;i<reservedSeats.size();i++){
            if(!visited.count(reservedSeats[i][0])){
                visited[reservedSeats[i][0]] = vector<bool>(11, false);
            }
            visited[reservedSeats[i][0]][reservedSeats[i][1]]=true;
        }
        int count=(n-visited.size())*2;
        for(auto &[row, seats] : visited) {

            bool left = !seats[2] &&
                        !seats[3] &&
                        !seats[4] &&
                        !seats[5];

            bool right = !seats[6] &&
                         !seats[7] &&
                         !seats[8] &&
                         !seats[9];

            bool middle = !seats[4] &&
                          !seats[5] &&
                          !seats[6] &&
                          !seats[7];

            if(left && right) {
                count += 2;
            }
            else if(left || right || middle){
                count+=1;
            }
        }
        return count;
    }
};