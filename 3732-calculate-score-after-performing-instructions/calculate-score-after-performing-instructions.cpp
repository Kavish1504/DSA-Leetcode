class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        vector<bool> visited(values.size(),false);
        long long score=0;
        for(int i=0;i<values.size();i++){
            if(visited[i])
                return score;

            visited[i] = true;
            if(instructions[i]=="jump"){
                i=i+values[i]-1;
                if(i<0 || i>=values.size()) return score;
            
            }
            else{
                score+=values[i];
            }
        }
        return score;
    }
};