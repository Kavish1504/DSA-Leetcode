class Solution {
public:
    void solve(vector<int>& nums,vector<int> temp,set<vector<int>>& ans,int index){
        if(index>=nums.size()){
            if(temp.size()>1)
            ans.insert(temp);
            return;
        }
        if(temp.empty() || nums[index]>=temp.back()){
            temp.push_back(nums[index]);
            solve(nums,temp,ans,index+1);
            temp.pop_back();
        }
        solve(nums,temp,ans,index+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> ans;
        solve(nums,temp,ans,0);
        vector<vector<int>> result;
        for(auto vec:ans){
            result.push_back(vec);
        }
        return result;
    }
};