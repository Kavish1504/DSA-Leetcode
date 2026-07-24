class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        int rounds=0;
        for(auto num:mp){
            if(num.second<2){
                return -1;
            }
            if(num.second%3==0){
                rounds+=(num.second/3);
            }
            else{
                rounds+=(num.second/3)+1;
            }
        }
        return rounds;
    }
};