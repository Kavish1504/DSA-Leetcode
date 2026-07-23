class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp,vector<int>& vis){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]) continue;

            vis[i] = 1;
            temp.push_back(nums[i]);

            solve(nums,ans,temp,vis);

            temp.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> visited(nums.size(),0);
        solve(nums,ans,temp,visited);
        return ans;
    }
};