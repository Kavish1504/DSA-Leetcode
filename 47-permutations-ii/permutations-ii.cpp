class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& result,vector<int>& temp,vector<bool>& visited){
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1] && !visited[i-1]){
                    continue;
                }
            if(!visited[i]){
                
                temp.push_back(nums[i]);
                visited[i]=true;
                solve(nums,result,temp,visited);
                temp.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> visited(nums.size(),false);
        vector<vector<int>> result;
        vector<int> temp;
        solve(nums,result,temp,visited);
        return result;
    }
};